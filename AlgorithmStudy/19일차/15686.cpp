#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define COORD pair<int, int>

using namespace std;

int N, M;
int village[51][51];
vector<COORD> chickens;
vector<COORD> house;
priority_queue<pair<int, COORD>> pq;

// 그래프를 그려서
// 행: 집 / 열: 치킨 각 가중치는 치킨 거리
// 열을 하나씩 지우면서 
// 그리디하게 가장 먼 거리

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int getChickenRoad(pair<int, int> coord) {
	int sum = 987654321;

	for(int i = 0; i < chickens.size(); i++)
		sum = min(sum, (abs(coord.first - chickens[i].first) + abs(coord.second - chickens[i].second)));

	return sum;
}

void close_chicken() {
	for (int i = 0; i < house.size(); i++) {
		pq.push({ getChickenRoad(house[i]), house[i] });
	}

	int sum = 0;
	while (pq.size() != 0)
	{
		if (pq.size() <= M) sum += pq.top().first;
		pq.pop();
	}

	cout << sum << "\n";
}

int main() {
	init();

	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> village[y][x];
			if (village[y][x] == 1) {
				house.push_back({ x, y });
			}
			else if (village[y][x] == 2) {
				chickens.push_back({ x, y });
			}
		}
	}

	close_chicken();
}
