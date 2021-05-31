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
	Trie* fail; // �������� ��, �̵��ؾ��� ������ ����ų ����

	bool isEnd; // �ϼ��� ���ڿ����� ǥ��(�Ϲ����� Ʈ���̿� ������ ����)

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
	// BFS�� ���� Ʈ���� ��带 �湮�ϸ� fail �Լ��� �����
	queue<Trie*> q;
	q.push(root);

	while (!q.empty())
	{
		Trie* current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Trie* next = current->go[i];

			if (!next) continue;

			// root�� �θ��� ������ �����ϸ� �θ�� ���ϰ� ���ƿ��� �ؾ���
			if (current == root) next->fail = root;
			else {
				Trie* dest = current->fail;

				// fail�� ������ ���� ����� ������ ã�ư���
				// next�� ������ �ִ� ������ ã�� ���� ��� �ö󰣴�
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