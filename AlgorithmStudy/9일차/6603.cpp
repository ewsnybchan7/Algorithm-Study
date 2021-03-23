#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> S;
vector<bool> check;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void findAllCombination(int idx, int n) {
	if (n == 6) {
		for (int i = 0; i < k; i++)
			if (check[i]) cout << S[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < k; i++) {
		if (!check[i]) {
			check[i] = true;
			findAllCombination(i, n + 1);
			check[i] = false;
		}
	}
}

int main() {
	init();

	while (true)
	{
		cin >> k;
		if (k == 0) break;

		S.resize(k); check.resize(k);
		for (int i = 0; i < k; i++) {
			cin >> S[i];
			check[i] = false;
		}

		findAllCombination(0, 0);
		cout << "\n";
	}
}