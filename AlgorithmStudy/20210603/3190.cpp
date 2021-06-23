#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, L;
int gameTime = 0;
deque<pair<int, int>> snake;
vector<pair<int, int>> apples;
queue<pair<int, char>> movement;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool isInMap(int x, int y) {
	if (x > N || x < 1 || y > N || y < 1)
		return false;
	
	return true;
}

bool crash(int x, int y) {
	for (int i = 0; i < snake.size(); i++) {
		if (snake[i].first == x && snake[i].second == y) return true;
	}
	return false;
}

bool isApple(int x, int y) {
	for (int i = 0; i < apples.size(); i++) {
		if (apples[i].first == x && apples[i].second == y) {
			apples.erase(apples.begin() + i);
			return true;
		}
	}
	return false;
}

void game() {
	int m[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	int mIndex = 0;

	while (true)
	{
		gameTime++;
		// 움직이고
		int x = snake.front().first;
		int y = snake.front().second;

		x += m[mIndex][0]; y += m[mIndex][1];
		
		// 벽에 부딪히는지 확인
		if (!isInMap(x, y)) break;
		if (crash(x, y)) break;


		// 살았으면 사과가 있는지 확인하고 움직임
		// 사과가 있으면 꼬리 움직임 X
		// 사과가 없으면 꼬리를 움직임
		// 꼬리를 움직이고 나서 머리랑 꼬리가 부딪히는지 확인
		if (!isApple(x, y)) snake.pop_back();

		snake.push_front({ x, y });
		
		if (!movement.empty() && gameTime == movement.front().first) {
			if (movement.front().second == 'L') mIndex = mIndex - 1 < 0 ? 3 : mIndex - 1;
			else if (movement.front().second == 'D') mIndex = mIndex + 1 > 3 ? 0 : mIndex + 1;
			movement.pop();
		}
	}

	cout << gameTime << "\n";
}

int main() {
	init();

	cin >> N;
	snake.push_back({ 1, 1 });

	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		apples.push_back({ x, y });
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int X; char C;
		cin >> X >> C;
		movement.push({ X, C });
	}

	game();
}
