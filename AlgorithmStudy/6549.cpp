#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	int n;

	while (true)
	{
		cin >> n;
		if (n == 0) break;

		stack<pair<long long, int>> s;
		long long graph;
		long long maxSize = 0;

		for (int i = 0; i < n; i++) {
			cin >> graph;
			if (s.size() == 0) s.push({ graph, i + 1});
			else {
				if (s.top().first < graph) s.push({ graph, i + 1});
				else {
					while (s.size() != 0 && s.top().first >= graph)
					{
						long long minHegith = s.top().first;
						s.pop();

						int left = s.size() == 0 ? 0 : s.top().second;
						
						maxSize = max(maxSize, minHegith * (i - left));
					}
					s.push({ graph, i + 1});
				}
			}
		}

		while (!s.empty())
		{
			long long minHeight = s.top().first;
			s.pop();

			int left = s.size() == 0 ? 0 : s.top().second;

			maxSize = max(maxSize, minHeight * (n - left));
		}

		cout << maxSize << "\n";
	}
}
