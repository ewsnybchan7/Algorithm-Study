#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> answer;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void duplicated_permutation(int n) {
	if (n == M) {
		for (int i : answer) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		answer[n] = i + 1;
		duplicated_permutation(n + 1);
	}
}

int main() {
	init();

	cin >> N >> M;
	answer.resize(M);

	duplicated_permutation(0);
}