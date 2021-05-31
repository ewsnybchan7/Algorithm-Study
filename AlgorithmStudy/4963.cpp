#include <iostream>
#include <vector>

using namespace std;

int w, h;
vector<vector<int>> map;
vector<vector<bool>> check;
int m[8][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0},
				{-1, -1}, {1, -1}, {-1, 1}, {1, 1} };
int N = 0;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool isValid(int x, int y) {
	if (x < 0 || x >= w) return false;
	if (y < 0 || y >= h) return false;
	if (check[y][x]) return false;
	return true;
}

void island_numbering(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int dx = x + m[i][0];
		int dy = y + m[i][1];

		if (isValid(dx, dy)) {
			check[dy][dx] = true;
			island_numbering(dx, dy);
		}
	}
}

void dfs() {
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (isValid(x, y)) {
				check[y][x] = true;
				N += 1;
				island_numbering(x, y);
			}
		}
	}
}

int main() {
	init();

	while(true) {
		cin >> w >> h;
		
		if (w == 0 && h == 0) break;

		map.resize(h);
		check.resize(h);

		for (int y = 0; y < h; y++) {
			map[y].resize(w);
			check[y].resize(w, false);

			for (int x = 0; x < w; x++) {
				cin >> map[y][x];
				if (map[y][x] == 0) check[y][x] = true;
				else check[y][x] = false;
			}
		}

		dfs();

		cout << N << endl;
		N = 0;
	}
}
