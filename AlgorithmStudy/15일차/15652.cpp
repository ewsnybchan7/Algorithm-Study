#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<int> num;
set<vector<int>> answer;

void duplicated_permutation(int n) {
	if (n == M) {
		answer.insert(num);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (n > 0 && num[n - 1] <= i + 1) {
			num[n] = i + 1;
			duplicated_permutation(n + 1);
		}
		else if (n == 0) {
			num[n] = i + 1;
			duplicated_permutation(n + 1);
		}
	}
}


int main() {
	cin >> N >> M;

	num.resize(M);

	duplicated_permutation(0);

	for (auto iter = answer.begin(); iter != answer.end(); iter++) {
		for (int i = 0; i < (*iter).size(); i++) {
			cout << (*iter)[i] << " ";
		}
		cout << "\n";
	}
}