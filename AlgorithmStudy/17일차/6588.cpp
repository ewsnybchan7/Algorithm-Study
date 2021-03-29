#include <iostream>
#include <vector>

using namespace std;

vector<int> prime;
vector<bool> check(1000001, false);

void init() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(0);
}

int main() {
	init();

	for (int i = 2; i <= 1000000; i++) {
		if (!check[i]) {
			prime.push_back(i);
			check[i] = true;
			int p = i;
			while (p <= 1000000)
			{
				check[p] = true;
				p += i;
			}
		}
	}

	int num;
	while (cin >> num && num != 0)
	{
		int n1 = 0, n2 = 0;
		bool find = false;
		for (int i = 1; prime[i] < num && !find; i++) {
			n1 = prime[i];

			for (int j = i; prime[j] < num && !find; j++) {
				n2 = prime[j];
				// 
				if (n1 + n2 == num) {
					find = true;
					cout << num << " = " << n1 << " + " << n2 << "\n";
					break;
				}
			}
		}

		if(!find)
			cout << "Goldbach's conjecture is wrong." << "\n";
	}
}