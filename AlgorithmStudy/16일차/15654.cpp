#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> number;
vector<int> answer;
vector<bool> check;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void permutation(int n) {
	if (n == M) {
		for (int i = 0; i < n; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			answer[n] = number[i];
			permutation(n + 1);
			check[i] = false;
		}
	}
}

int main() {
	init();

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		number.push_back(num);
	}

	sort(number.begin(), number.end());

	check.resize(N); answer.resize(M);

	permutation(0);
}