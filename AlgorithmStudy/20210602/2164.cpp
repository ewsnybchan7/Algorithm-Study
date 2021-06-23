#include <iostream>
#include <queue>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	queue<int> q;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) q.push(i + 1);

	// 카드가 1장 남을 때까지 반복한다
	while (q.size() > 1)
	{
		// 1. 카드를 버리기
		q.pop();

		// 버리고 나서 1장이 남을 수 있음
		if (q.size() == 1) break;

		// 2. 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮김
		int temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << q.front() << "\n";
}
