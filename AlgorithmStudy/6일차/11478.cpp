#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string S;
unordered_set<string> answer;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	getline(cin, S);

	int len = S.size();

	string sub = "";
	for (int i = 0; i < len; i++) {
		sub = "";
		for (int j = i; j < len; j++) {
			sub += S[j];
			answer.insert(sub);
		}
	}

	cout << answer.size() << "\n";
}