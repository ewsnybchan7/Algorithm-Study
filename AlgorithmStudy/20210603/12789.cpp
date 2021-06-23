#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	queue<int> line;
	stack<int> temp;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		line.push(n);
	}

	int index = 1;
	int check = 1;
	while (index <= N)
	{
		if (!line.empty() && line.front() == index) {
			line.pop();
			index++;
		}
		else {
			if (!temp.empty() && temp.top() == index) {
				temp.pop();
				index++;
			}
			else {
				if (line.empty()) {
					cout << "Sad" << "\n";
					return 0;
				}
				else {
					temp.push((line.front()));
					line.pop();
				}
			}
		}
	}

	cout << "Nice" << "\n";
}
