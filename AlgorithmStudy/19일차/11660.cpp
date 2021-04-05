#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int table[1025][1025];
vector<vector<int>> dp;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> table[y][x];
		}
	}

	dp.resize(1);
	for (int x = 0; x < N; x++) {
		int sum_y = 0;
		vector<int> dp_y;
		dp_y.push_back(sum_y);
		for (int y = 0; y < N; y++) {
			sum_y += table[y][x];
			dp_y.push_back(sum_y);
		}
		dp.push_back(dp_y);
	}

	for (int t = 0; t < M; t++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		int sum = 0;
		for (int x = x1; x <= x2; x++) {
			sum += (dp[x][y2] - dp[x][y1 - 1]);
		}

		cout << sum << "\n";
	}
}
