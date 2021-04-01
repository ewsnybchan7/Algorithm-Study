#include <iostream>
#include <set>

using namespace std;

int M;
set<int, greater<int>> S;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void add(int x) {
	S.insert(x);
}

void remove(int x) {
	S.erase(x);
}

int check(int x) {
	return !(S.find(x) == S.end());
}

void toggle(int x) {
	if (check(x)) remove(x);
	else add(x);
}

void all() {
	for (int i = 0; i < 20; i++) {
		add(i + 1);
	}
}

void empty() {
	S.clear();
}


int main() {
	init();
	
	cin >> M;

	for (int i = 0; i < M; i++) {
		string s;
		int x;
		cin >> s;

		if (s == "add") {
			cin >> x;
			add(x);
		}
		else if (s == "remove") {
			cin >> x;
			remove(x);
		}
		else if (s == "check") {
			cin >> x;
			cout << check(x) << "\n";
		}
		else if (s == "toggle") {
			cin >> x;
			toggle(x);
		}
		else if (s == "all") {
			all();
		}
		else if (s == "empty") {
			empty();
		}
	}
}