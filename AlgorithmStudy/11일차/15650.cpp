#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<bool> numbers;
set<vector<bool>> answer;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void permutation_2(int n) {
	if (n == M) {
		answer.insert(numbers);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!numbers[i]) {
			numbers[i] = true;
			permutation_2(n + 1);
			numbers[i] = false;
		}
	}
}

int main() {
	init();

	cin >> N >> M;

	numbers.resize(N);

	permutation_2(0);

	for (auto iter = answer.rbegin(); iter != answer.rend(); iter++) {
		for (int i = 0; i < N; i++) {
			if ((*iter)[i]) cout << i + 1 << " ";
		}
		cout << "\n";
	}
}