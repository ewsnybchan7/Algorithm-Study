#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int R, C;
vector<string> grid;
queue<pair<int, int>> q;
int m[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool isValid(int x, int y) {
	if (x < 0 || x >= C) return false;
	if (y < 0 || y >= R) return false;
	return true;
}


int main() {
	init();

	cin >> R >> C;

	grid.resize(R);
	for (int r = 0; r < R; r++) {
		cin >> grid[r];
		
		for (int c = 0; c < C; c++) {
			if (grid[r][c] == 'S') {
				q.push({ c, r });
			}
		}
	}

	bool check = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + m[i][0];
			int dy = y + m[i][1];

			if (isValid(dx, dy)) {
				if (grid[dy][dx] == '.') {
					grid[dy][dx] = 'D';
				}
				else if (grid[dy][dx] == 'W') {
					check = false;
				}
			}
		}
	}

	cout << check << "\n";
	if (check) {
		for (int y = 0; y < R; y++) {
			cout << grid[y] << "\n";
		}
	}
}
