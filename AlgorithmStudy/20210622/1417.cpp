#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, vote;
priority_queue<int> pq;
vector<int> candidate;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> N;

	cin >> vote;
	
	for (int i = 0; i < N - 1; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	int result = 0;
	while (!pq.empty() && vote <= pq.top())
	{
		int num = pq.top();
		pq.pop();

		num -= 1;
		vote += 1;
		result++;

		pq.push(num);
	}

	cout << result << "\n";
}
