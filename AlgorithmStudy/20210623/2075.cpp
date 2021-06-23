#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> N;

	for (int i = 0; i < N * N; i++) {
		int n;
		cin >> n;
		pq.push(n);

		// 메모리초과가 나기 때문에
		// 우선순위 큐에 N개만 존재하도록 함
		if (pq.size() > N) pq.pop(); 
	}

	// 오름차순으로 정렬했고 N개만 존재하도록 우선순위 큐에 저장했기에
	// 우선순위 큐 제일 상단에 있는 수는 N번째로 큰 수다
	cout << pq.top() << "\n";
}
