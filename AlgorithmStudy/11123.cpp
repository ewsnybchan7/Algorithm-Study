#include <iostream>
#include <vector>

using namespace std;

int T, H, W; // testcase height width
vector<string> grid;
vector<vector<bool>> check;
int m[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
int N;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool isValid(int x, int y) {
	if (x < 0 || x >= W) return false;
	if (y < 0 || y >= H) return false;
	if (check[y][x]) return false;
	return true;
}

void sheep_numbering(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int dx = x + m[i][0];
		int dy = y + m[i][1];

		if (isValid(dx, dy)) {
			check[dy][dx] = true;
			sheep_numbering(dx, dy);
		}
	}
}

void dfs() {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (check[y][x]) continue;
			
			check[y][x] = true;
			sheep_numbering(x, y);
			N++;
		}
	}
}

int main() {
	init();

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W;
		
		grid.resize(H);
		check.resize(H);
		for (int h = 0; h < H; h++) {
			cin >> grid[h];

			check[h].resize(W, false);
			for (int w = 0; w < W; w++) {
				if (grid[h][w] == '.') {
					check[h][w] = true;
				}
				else {
					check[h][w] = false;
				}
			}
		}

		dfs();

		cout << N << "\n";
		N = 0;
	}
}
