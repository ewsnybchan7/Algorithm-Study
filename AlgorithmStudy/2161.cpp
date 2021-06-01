#include <iostream>
#include <queue>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	int N;
	queue<int> cards;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cards.push(i + 1);
	}

	while (!cards.empty())
	{
		cout << cards.front() << " ";
		cards.pop();

		if (!cards.empty()) {
			int front = cards.front();
			cards.pop();
			cards.push(front);
		}
	}
}
