#include <iostream>
#include <vector>

using namespace std;

int N, answer = 0;
int game[21][21];
int m[4][2] = { {0,-1}, {0, 1}, {-1, 0}, {1, 0} };

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool isValid() {

}

void moveToDirection(int x, int y, int dx, int dy) {
	if(dy )
	if (game[y + dy][x + dx] == game[y][x]) {
		game[y + dy][x + dx] *= 2;
		game[y][x] = 0;
	}
}

void dfs(int n) {
	if (n == 5) {

	}

	for (int i = 0; i < 4; i++) {
		
	}
}

int main() {
	init();

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> game[y][x];
		}
	}

	
}