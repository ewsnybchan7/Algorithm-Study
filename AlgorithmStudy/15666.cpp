#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> result;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void NandM_12(int n) {
	if (n - 1 == M) {
		for (int i = 1; i <= M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = -1;

	for (int i = 0; i < N; i++) {
		if (numbers[i] != prev && numbers[i] >= result[n-1]) {
			result[n] = numbers[i];
			NandM_12(n + 1);
			prev = numbers[i];
		}
	}
}

int main() {
	init();

	cin >> N >> M;
	numbers.resize(N);
	result.resize(M + 1);
	result[0] = -1;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());

	NandM_12(1);
}
