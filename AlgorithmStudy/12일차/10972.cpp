#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> numbers;
vector<bool> check;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void next_permutation() {
	int n = N;
	
	do
	{
		int num = numbers[--n];

		check[num] = false;
		for (int i = num + 1; i <= N; i++) {
			if (!check[i]) {
				check[i] = true;
				numbers[n++] = i;
				i = 0;
			}
		}
	} while (n < N && n > 0);

	if (n == 0) {
		cout << -1 << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		cout << numbers[i] << " ";
	}
	cout << "\n";
}

int main() {
	init();

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	check.resize(N + 1);
	for (int i = 0; i < N + 1; i++) check[i] = true;

	next_permutation();
}
