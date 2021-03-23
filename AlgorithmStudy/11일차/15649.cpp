#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers;
vector<bool> check;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void permutation(int n) {
	if (n == M) {
		for (int i = 0; i < n; i++) {
			cout << numbers[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			numbers[n] = i + 1;
			permutation(n + 1);
			check[i] = false;
		}
	}
}

int main() {
	init();

	cin >> N >> M;

	numbers.resize(N); check.resize(N);
	for (int i = 0; i < N; i++) check[i] = false;

	permutation(0);
}