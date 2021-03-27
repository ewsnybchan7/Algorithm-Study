#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
int upAirR, upAirC;
int downAirR, downAirC;
int map[50][50];

bool validMap(int y, int x) {
	if (x < 0 || x >= C) return false;
	if (y < 0 || y >= R) return false;
	if (map[y][x] == -1) return false;
	return true;
}

void spreadFineDust() {
	int temp[50][50];

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			temp[r][c] = map[r][c];
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] == -1) continue;

			int spread = 0; vector<pair<int, int>> spreads;
			if (validMap(r - 1, c)) { spread++; spreads.push_back({ r - 1, c }); }
			if (validMap(r, c + 1)) { spread++; spreads.push_back({ r, c + 1 }); }
			if (validMap(r + 1, c)) { spread++; spreads.push_back({ r + 1, c }); }
			if (validMap(r, c - 1)) { spread++; spreads.push_back({ r, c - 1 }); }

			int dust = map[r][c] / 5;
			temp[r][c] -= (dust * spread);
			for (int i = 0; i < spreads.size(); i++) {
				temp[spreads[i].first][spreads[i].second] += dust;
			}
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			map[r][c] = temp[r][c];
		}
	}
}

void airPurify() {
	int temp[50][50];

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			temp[r][c] = map[r][c];
		}
	}
	
	// upside
	for (int c = 1; c < C - 1; c++) {
		if (map[upAirR][c - 1] == -1) temp[upAirR][c] = 0;
		else temp[upAirR][c] = map[upAirR][c - 1];
	}
	temp[upAirR][C - 1] = map[upAirR][C - 2];
	for (int r = upAirR - 1; r >= 1; r--) temp[r][C - 1] = map[r + 1][C - 1];
	temp[0][C - 1] = map[1][C - 1];
	for (int c = C - 2; c >= 1; c--) temp[0][c] = map[0][c + 1];
	temp[0][0] = map[0][1];
	for (int r = 1; r < upAirR; r++) temp[r][0] = map[r - 1][0];

	// downside
	for (int c = 1; c < C - 1; c++) {
		if (map[downAirR][c - 1] == -1) temp[downAirR][c] = 0;
		else temp[downAirR][c] = map[downAirR][c - 1];
	}
	temp[downAirR][C - 1] = map[downAirR][C - 2];
	for (int r = downAirR + 1; r < R; r++) temp[r][C - 1] = map[r - 1][C - 1];
	temp[R - 1][C - 1] = map[R - 2][C - 1];
	for (int c = C - 2; c >= 1; c--) temp[R - 1][c] = map[R - 1][c + 1];
	temp[R - 1][0] = map[R - 1][1];
	for (int r = R - 2; r > downAirR; r--) temp[r][0] = map[r + 1][0];


	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			map[r][c] = temp[r][c];
		}
	}
}

int main() {
	cin >> R >> C >> T;

	bool air = false;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			if (map[r][c] == -1 && !air) {
				upAirR = r; upAirC = c;
				downAirR = r + 1; downAirC = c;
				air = true;
			}
		}
	}

	for (int t = 0; t < T; t++) {
		spreadFineDust();
		airPurify();
	}

	int sum = 2;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {	
			sum += map[r][c];
		}
	}

	cout << sum << "\n";
}