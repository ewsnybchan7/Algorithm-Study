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

void NandM_11(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = -1;

	for (int i = 0; i < N; i++) {
		if (numbers[i] != prev) {
			result[n] = numbers[i];
			NandM_11(n + 1);
			prev = numbers[i];
		}
	}
}

int main() {
	init();

	cin >> N >> M;

	numbers.resize(N);
	result.resize(M);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	
	sort(numbers.begin(), numbers.end());
	
	NandM_11(0);
}
