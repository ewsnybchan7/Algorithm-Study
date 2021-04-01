#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define coord pair<int, int>
const int MAX = 987654321;

using namespace std;

int water[21][21];
int visit[21][21];
int N;
int shark_x, shark_y;
int shark_size = 2, eat_count = 0;
int m[4][2] = { {0, -1}, {-1, 0}, {1, 0}, {0, 1} };
vector<pair<coord, int>> fishes;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool isValid(int x, int y) {
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= N) return false;
	if (water[y][x] > shark_size) return false;
	if (visit[y][x]) return false;
	return true;
}

void BFS() {
	queue<coord> q;
	q.push({ shark_x, shark_y });
	memset(visit, 0, sizeof(visit));
	int distance = MAX;

	while (!q.empty())
	{
		coord current = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = current.first + m[d][0];
			int ny = current.second + m[d][1];

			if (isValid(nx, ny)) {
				visit[ny][nx] = visit[current.second][current.first] + 1;

				if (water[ny][nx] && water[ny][nx] < shark_size) {
					if (visit[ny][nx] <= distance) {
						distance = visit[ny][nx];
						fishes.push_back({ {distance,  ny}, nx });
					}
				}

				q.push({ nx, ny });
			}
		}
	}
}

void eat() {
	int result = 0;

	while (true)
	{
		fishes.clear();
		BFS();
		
		if (fishes.empty()) break;
		else {
			sort(fishes.begin(), fishes.end());
			pair<coord, int> fish = fishes[0];
			eat_count++;
			result += fish.first.first;
			water[fish.first.second][fish.second] = 0;
			shark_x = fish.second; shark_y = fish.first.second;
			if (shark_size == eat_count) {
				shark_size++; 
				eat_count = 0;
			}
		}
	}

	cout << result << "\n";
	return;
}

int main() {
	init();

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> water[y][x];
			if (water[y][x] == 9) {
				water[y][x] = 0;
				shark_x = x; shark_y = y;
			}
		}
	}

	eat();
}