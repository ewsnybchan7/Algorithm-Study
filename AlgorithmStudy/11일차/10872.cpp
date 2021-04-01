#include <iostream>

using namespace std;

int N;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int factorial(int n) {
	if (n == 0) return 1;
	else return factorial(n - 1) * n;
}

int main() {
	init();

	cin >> N;
	cout << factorial(N) << "\n";
}