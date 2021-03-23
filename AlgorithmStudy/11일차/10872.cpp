#include <iostream>

using namespace std;

int N;

int factorial(int n) {
	if (n == 0) return 1;
	else return factorial(n - 1) * n;
}

int main() {
	cin >> N;
	cout << factorial(N) << "\n";
}