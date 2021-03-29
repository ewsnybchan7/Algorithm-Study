#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
vector<int> number;
vector<int> answer;
vector<bool> check;

void combination(int n) {
	if (n == M) {
		for (int i = 0; i < n; i++) {
			cout << number[answer[i]] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (n == 0) {
			if (!check[i]) {
				check[i] = true;
				answer[n] = i;
				combination(n + 1);
				check[i] = false;
			}
		}
		else {
			if (!check[i] && number[i] > number[answer[n - 1]]) {
				check[i] = true;
				answer[n] = i;
				combination(n + 1);
				check[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		number.push_back(num);
	}

	check.resize(N); answer.resize(N);
	sort(number.begin(), number.end());

	combination(0);
}