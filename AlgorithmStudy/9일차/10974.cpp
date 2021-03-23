#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> numbers;
vector<bool> check;
vector<int> answer;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}


void permutation(int n) {
	if (n == N) {
		for (int i = 0; i < N; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			answer[n] = numbers[i];
			permutation(n + 1);
			check[i] = false;
		}
	}
}

int main() {
	init();

	cin >> N;

	for (int i = 0; i < N; i++)
		numbers.push_back(i + 1);

	check.resize(N);
	answer.resize(N);

	for (int i = 0; i < N; i++)
		check[i] = false;

	permutation(0);
}