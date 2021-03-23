#include <iostream>
#include <stack>

using namespace std;

int N, M;
int answer = 0;
stack<char> S;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> N;
	cin >> M;

	char prev = 0;
	for (int i = 0; i < M; i++) {
		char s;
		cin >> s;

		if (s == 'I') {
			if (S.size() == 0) {
				S.push(s);
			}
			else {
				if (prev == 'I') {
					while (S.size() > 1) S.pop();
				}
				else {
					if (S.size() == N) {
						answer++;
					}
					else {
						S.push(s);
					}
				}
			}
		}
		else {
			if (prev == 'O')
				while (S.size() != 0) S.pop();
		}

		prev = s;
	}

	cout << answer << "\n";
}