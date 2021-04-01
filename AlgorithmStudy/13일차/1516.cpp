#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

vector<int> times;
vector<priority_queue<int>> pq;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int calculateTime(int n) {
	if (pq[n].empty()) return times[n];
	
	int maxTime = 0;

	while (!pq[n].empty())
	{
		int index = pq[n].top();
		pq[n].pop();

		maxTime = max(maxTime, calculateTime(index));
	}

	times[n] = times[n] + maxTime;
	return times[n];
}

int main() {
	init();

	cin >> N;

	times.resize(N); pq.resize(N);

	for (int i = 0; i < N; i++) {
		int time;
		cin >> time;
		times[i] = time;

		priority_queue<int> check;
		int n;
		cin >> n;
		while (n != -1)
		{
			check.push(n - 1);
			cin >> n;
		}
		pq[i] = check;
	}

	for (int i = 0; i < N; i++) {
		cout << calculateTime(i) << "\n";
	}
}