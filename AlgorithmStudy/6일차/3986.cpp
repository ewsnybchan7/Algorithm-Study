#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool check_good_word(string& s) {
	stack<char> word;

	for (int i = 0; i < s.size(); i++) {
		if (!word.empty()) {
			if (word.top() == s[i]) word.pop();
			else word.push(s[i]);
		}
		else word.push(s[i]);
	}

	if (word.empty()) return true;
	else return false;
}


int main() {
	init();

	cin >> N;

	int result = 0;
	for (int t = 0; t < N; t++) {
		string s;
		cin >> s;

		if (check_good_word(s)) result++;
	}

	cout << result << "\n";
}