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
		// 1. 제일 위에 있는 카드를 버리고 출력
		cout << cards.front() << " ";
		cards.pop();

		// 아직 카드가 남았을 경우 / 2. 위에 있는 카드를 밑으로 옮기기
		if (!cards.empty()) {
			int front = cards.front();
			cards.pop();
			cards.push(front);
		}
	}
}
