#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

char a[50][50];
int answer;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int sumRow(int r) {
	int sum = 1;
	int _max = 0;

	for (int i = 1; i < N; i++) {
		if (a[r][i - 1] == a[r][i]) sum++;
		else {
			_max = max(_max, sum);
			sum = 1;
		}
	}

	_max = max(_max, sum);

	return _max;
}

int sumCol(int c) {
	int sum = 1;
	int _max = 0;

	for (int i = 1; i < N; i++) {
		if (a[i - 1][c] == a[i][c]) sum++;
		else {
			_max = max(_max, sum);
			sum = 1;
		}
	}

	_max = max(_max, sum);

	return _max;
}

int maxSum() {
	int maxSum = 0;
	
	for (int r = 0; r < N; r++)
		maxSum = max(maxSum, sumRow(r));

	for (int c = 0; c < N; c++)
		maxSum = max(maxSum, sumCol(c));

	return maxSum;
}

int findSwapSum(int x, int y, int dx, int dy) {
	if (x + dx < 0 || x + dx >= N) return -1;
	if (y + dy < 0 || y + dy >= N) return -1;
	
	if (a[y][x] == a[y + dy][x + dx]) return -1;

	swap(a[y][x], a[y + dy][x + dx]);
	answer = max(answer, sumRow(y));
	answer = max(answer, sumCol(x));
	answer = dy != 0 ? max(answer, sumRow(y + dy)) : answer;
	answer = dx != 0 ? max(answer, sumCol(x + dx)) : answer;
	swap(a[y][x], a[y + dy][x + dx]);

	return answer;
}

// 모든 것을 BP하는 것이 아닌
// YCP    X X X
// CYZ    X C O
// CCP    O O O      가운데를 기준으로 옆과 같이 비교를 진행하면 된다. 인접한 것중 반절만 진행하면 된다.
// a[y][x+1], a[y+1][x+1], a[y+1][x], a[y+1][x-1]
// if 둘이 같다면 무시
// else 다르다면 교환하기
//		여기서 모든 것을 확인하는 것이 아니라 [2][2] [3]]3]이 교환했다면
//		2행과 2열, 3행과 3열에서 최대값을 구한다.
// 만약 길이가 N이라면 더이상 구할 필요가 없다


int main() {
	init();

	cin >> N;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> a[y][x];

	answer = maxSum();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			findSwapSum(x, y, 1, 0);
			findSwapSum(x, y, 0, 1);
		}
	}

	cout << answer << "\n";

}