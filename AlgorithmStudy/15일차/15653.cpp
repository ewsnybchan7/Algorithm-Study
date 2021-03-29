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

struct State {
	int rx;
	int ry;
	int bx;
	int by;
	int count;
};

bool isGoal(int x, int y) {
	if (x == hX && y == hY) return true;
	else return false;
}

bool isValid(int x, int y, int tx, int ty, bool isRed) {
	if (isGoal(x, y)) {
		if (isRed) redgoal = true;
		else bluegoal = true;

		return true;
	}

	if (x < 0 || x >= M) return false;
	if (y < 0 || y >= N) return false;
	if (map[y][x] == '#') return false;
	if (x == tx && y == ty) return false;
	
	return true;
}

vector<int> moveUp(int rx, int ry, int bx, int by) {
	int rtx = rx, rty = ry;
	int btx = bx, bty = by;

	if (ry <= by) {
		while (isValid(rtx, rty - 1, btx, bty, true)) { rty--; if (redgoal || bluegoal) break; } 
		while (isValid(btx, bty - 1, rtx, rty, false)) { bty--; if (redgoal || bluegoal) break; }
	}
	else {
		while (isValid(btx, bty - 1, rtx, rty, false)) { bty--; if (redgoal || bluegoal) break; }
		while (isValid(rtx, rty - 1, btx, bty, true)) { rty--; if (redgoal || bluegoal) break; }
	}

	rx = rtx, ry = rty, bx = btx, by = bty;

	return { rx, ry, bx, by };
}

vector<int> moveDown(int rx, int ry, int bx, int by) {
	int rtx = rx, rty = ry;
	int btx = bx, bty = by;

	if (ry >= by) {
		while (isValid(rtx, rty + 1, btx, bty, true)) { rty++; if (redgoal || bluegoal) break; }
		while (isValid(btx, bty + 1, rtx, rty, false)) { bty++; if (redgoal || bluegoal) break; }
	}
	else {
		while (isValid(btx, bty + 1, rtx, rty, false)) { bty++; if (redgoal || bluegoal) break; }
		while (isValid(rtx, rty + 1, btx, bty, true)) { rty++; if (redgoal || bluegoal) break; }
	}

	rx = rtx, ry = rty, bx = btx, by = bty;

	return { rx, ry, bx, by };
}

vector<int> moveLeft(int rx, int ry, int bx, int by) {
	int rtx = rx, rty = ry;
	int btx = bx, bty = by;

	if (rx <= bx) {
		while (isValid(rtx - 1, rty, btx, bty, true)) { rtx--; if (redgoal || bluegoal) break; }
		while (isValid(btx - 1, bty, rtx, rty, false)) { btx--; if (redgoal || bluegoal) break; }
	}
	else {
		while (isValid(btx - 1, bty, rtx, rty, false)) { btx--; if (redgoal || bluegoal) break; }
		while (isValid(rtx - 1, rty, btx, bty, true)) { rtx--; if (redgoal || bluegoal) break; }
	}

	rx = rtx, ry = rty, bx = btx, by = bty;

	return { rx, ry, bx, by };
}

vector<int> moveRight(int rx, int ry, int bx, int by) {
	int rtx = rx, rty = ry;
	int btx = bx, bty = by;

	if (rx >= bx) {
		while (isValid(rtx + 1, rty, btx, bty, true)) { rtx++; if (redgoal || bluegoal) break; }
		while (isValid(btx + 1, bty, rtx, rty, false)) { btx++; if (redgoal || bluegoal) break; }
	}
	else {
		while (isValid(btx + 1, bty, rtx, rty, false)) { btx++; if (redgoal || bluegoal) break; }
		while (isValid(rtx + 1, rty, btx, bty, true)) { rtx++; if (redgoal || bluegoal) break; }
	}

	rx = rtx, ry = rty, bx = btx, by = bty;

	return { rx, ry, bx, by };
}

void escapeBall() {
	queue<State> q;
	q.push({ rX, rY, bX, bY, 0 });
	visited[rX][rY][bX][bY] = true;

	while (!q.empty())
	{
		int rtx = q.front().rx;
		int rty = q.front().ry;
		int btx = q.front().bx;
		int bty = q.front().by;
		int count = q.front().count;
		q.pop();

		if (isGoal(rtx, rty) && isGoal(btx, bty)) continue;
		if (!isGoal(rtx, rty) && isGoal(btx, bty)) continue;

		if (isGoal(rtx, rty) && !isGoal(btx, bty)) {
			cout << count << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			vector<int> coordinate;

			switch (i)
			{
			case 0:
				coordinate = moveUp(rtx, rty, btx, bty);
				break;
			case 1:
				coordinate = moveDown(rtx, rty, btx, bty);
				break;
			case 2:
				coordinate = moveLeft(rtx, rty, btx, bty);
				break;
			case 3:
				coordinate = moveRight(rtx, rty, btx, bty);
				break;
			}

			if (coordinate[0] == coordinate[2] && coordinate[1] == coordinate[3]) continue;
			
			if (!visited[coordinate[1]][coordinate[0]][coordinate[3]][coordinate[2]]) {
				q.push({ coordinate[0], coordinate[1], coordinate[2], coordinate[3], count + 1 });
				visited[coordinate[1]][coordinate[0]][coordinate[3]][coordinate[2]] = true;
			}
		}
	}
}

int main() {
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

	escapeBall();
}