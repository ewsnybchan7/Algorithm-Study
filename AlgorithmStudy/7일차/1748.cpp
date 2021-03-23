#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

string N;

int main() {
	cin >> N;

	int n = N.size();
	int sum = 0;

	sum = (stoi(N) - (pow(10, n - 1) - 1)) * n;

	for (int i = n - 1; i >= 0; i--) {
		sum += 9 * i * pow(10, i - 1);
	}

	cout << sum << "\n";
}