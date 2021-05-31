#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int T;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int DNAtoi(char dna) {
	switch (dna)
	{
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	}
}

struct Trie {
	Trie* go[4];
	Trie* fail; // 실패했을 때, 이동해야할 지점을 가리킬 변수

	bool isEnd; // 완성된 문자열인지 표시(일반적인 트라이에 나오는 개념)

	Trie() {
		fill(go, go + 4, nullptr);
		isEnd = false;
		fail = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 4; i++)
			if (go[i]) delete go[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			isEnd = true;
			return;
		}

		int next = DNAtoi(*key);

		if (!go[next]) {
			go[next] = new Trie;
		}
		go[next]->insert(key + 1);
	}
};

Trie* root;

void makeFail() {
	// BFS를 통해 트라이 노드를 방문하며 fail 함수를 만든다
	queue<Trie*> q;
	q.push(root);

	while (!q.empty())
	{
		Trie* current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Trie* next = current->go[i];

			if (!next) continue;

			// root가 부모라면 무조건 실패하면 부모로 향하게 돌아오게 해야함
			if (current == root) next->fail = root;
			else {
				Trie* dest = current->fail;

				// fail을 참조할 가장 가까운 조상을 찾아간다
				// next를 가지고 있는 조상을 찾기 위해 계속 올라간다
				while (dest != root && !dest->go[i])
					dest = dest->fail;

				if (dest->go[i]) dest = dest->go[i];
				next->fail = dest;
			}

			if (next->fail->isEnd) next->isEnd = true;

			q.push(next);
		}
	}
}

int search(const string& s) {
	Trie* cursor = root;
	int match = 0;

	for (int i = 0; i < s.size(); i++) {
		int index = DNAtoi(s[i]);

		while (cursor != root && !cursor->go[index])
			cursor = cursor->fail;

		if (cursor->go[index]) cursor = cursor->go[index];

		if (cursor->isEnd) match++;
	}

	return match;
}

int main() {
	init();

	cin >> T;


	for (int i = 0; i < T; i++) {
		int n, m;
		string dna;
		string marker;
		int match = 0;

		cin >> n >> m;
		cin >> dna; cin.ignore();
		cin >> marker; cin.ignore();

		root = new Trie;
		root->insert(marker.c_str());
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				string temp = marker;
				reverse(temp.begin() + i, temp.begin() + j + 1);
				root->insert(temp.c_str());
			}
		}

		makeFail();
		cout << search(dna) << "\n";

		delete root;
	}
}