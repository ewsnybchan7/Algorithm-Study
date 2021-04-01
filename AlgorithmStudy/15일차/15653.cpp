#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define Node pair<int, int>

int N, M;
int rX, rY, bX, bY, hX, hY;
bool redgoal = false;
bool bluegoal = false;
char map[10][10];
bool visited[10][10][10][10];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}


int main() {
	init();

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'R') {
				rX = x, rY = y;
			}
			else if (map[y][x] == 'B') {
				bX = x, bY = y;
			}
			else if (map[y][x] == 'O') {
				hX = x; hY = y;
			}
		}
	}

	memset(visited, false, sizeof(visited));

}