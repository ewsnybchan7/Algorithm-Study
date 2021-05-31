#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<string> map;
vector<vector<bool>> check;
priority_queue<int, vector<int>, greater<int>> pq;

int m[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
int N;


void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool isValid(int x, int y) {
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= N) return false;
	if (check[y][x] == true) return false;
	return true;
}

void house_numbering(int x, int y, int& n) {
	for (int i = 0; i < 4; i++) {
		int dx = x + m[i][0];
		int dy = y + m[i][1];

		if (isValid(dx, dy)) {
			check[dy][dx] = true;
			n += 1;
			house_numbering(dx, dy, n);
		}
	}
}

void dfs() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '0') {
				check[y][x] = true;
				continue;
			}
				
			if (isValid(x, y)) {
				int num = 1;

				check[y][x] = true;
				house_numbering(x, y, num);

				pq.push(num);
			}
		}
	}
}

int main() {
	init();

	cin >> N;

	map.resize(N);
	check.resize(N);
	for (int i = 0; i < N; i++) {
		map[i].resize(N);
		check[i].resize(N, false);
	}

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '0') check[y][x] = true;
		}
	}

	dfs();

	cout << pq.size() << "\n";
	while (!pq.empty())
	{
		cout << pq.top() << "\n";
		pq.pop();
	}
}
