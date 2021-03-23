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

// ��� ���� BP�ϴ� ���� �ƴ�
// YCP    X X X
// CYZ    X C O
// CCP    O O O      ����� �������� ���� ���� �񱳸� �����ϸ� �ȴ�. ������ ���� ������ �����ϸ� �ȴ�.
// a[y][x+1], a[y+1][x+1], a[y+1][x], a[y+1][x-1]
// if ���� ���ٸ� ����
// else �ٸ��ٸ� ��ȯ�ϱ�
//		���⼭ ��� ���� Ȯ���ϴ� ���� �ƴ϶� [2][2] [3]]3]�� ��ȯ�ߴٸ�
//		2��� 2��, 3��� 3������ �ִ밪�� ���Ѵ�.
// ���� ���̰� N�̶�� ���̻� ���� �ʿ䰡 ����


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