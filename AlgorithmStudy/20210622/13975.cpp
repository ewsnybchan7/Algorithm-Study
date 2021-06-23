#include <iostream>
#include <queue>

using namespace std;

int T, K;
priority_queue<long long, vector<long long>, greater<long long>> files;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> T;

	for (int i = 0; i < T; i++) {
		long long sum = 0;
		cin >> K;


		for (int k = 0; k < K; k++) {
			long long num;
			cin >> num;
			files.push(num);
		}

		while (!files.empty())
		{
			long long first = files.top();
			files.pop();
			long long second = files.top();
			files.pop();
			
			sum += first + second;
			
			if (files.empty()) break;
			files.push(first + second);
		}

		cout << sum << "\n";
	}
}