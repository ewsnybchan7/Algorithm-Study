#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int f(int a, int b) {
	if (b == 0) return 1;
	else {
		if (!(b % 2)) return f(a, b / 2) * f(a, b / 2);
		else return a * f(a, b - 1);
	}
}

int main() {
	init();

	cout << f(3, 4) << "\n";
}
