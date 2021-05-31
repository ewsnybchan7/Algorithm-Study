#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int graph[1001][1001];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void dijkstra() {
	vector<priority_queue<int>> dist;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n + 1; i++) {
		priority_queue<int> q;
		dist.push_back(q);
	}

	dist[1].push(0);
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int vertex = pq.top().second;
		int weight = pq.top().first;

		pq.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[vertex][i]) {
				int newdist = weight + graph[vertex][i];

				if (dist[i].size() < k) {
					dist[i].push(newdist);
					pq.push({ newdist, i });
				}
				else {
					if (dist[i].top() > newdist) {
						dist[i].pop();
						dist[i].push(newdist);
						pq.push({ newdist, i });
					}
				}
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		if (dist[i].size() < k) cout << -1 << "\n";
		else cout << dist[i].top() << "\n";
	}
}

int main() {
	init();

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	dijkstra();
}