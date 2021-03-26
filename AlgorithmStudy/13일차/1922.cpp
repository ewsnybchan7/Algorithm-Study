#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define P pair<int, int>

int graph[1001][1001];
priority_queue<P, vector<P>, greater<P>> vertex;
vector<bool> check(1001, false);
int N, M;

int main() {
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}

	vertex.push({ 0, 1 });

	int sum = 0;
	while (!vertex.empty())
	{
		int v = vertex.top().second;
		int e = vertex.top().first;
		vertex.pop();

		if (check[v]) continue;
		sum += e;

		for (int i = 1; i < N + 1; i++) {
			if (graph[v][i] && !check[i]) {
				vertex.push({ graph[v][i], i });
			}
		}

		check[v] = true;
	}

	cout << sum << "\n";
}