#include <iostream>
#include <vector>

using namespace std;

int N;
int answer = 0;
vector<int> prime;
vector<bool> checkPrime;

int main() {
	cin >> N;

	checkPrime.resize(N + 1);

	for (int i = 2; i < N + 1; i++) {
		if (!checkPrime[i]) {
			prime.push_back(i);
			int p = i;

			while (p <= N)
			{
				checkPrime[p] = true;
				p += i;
			}
		}
	}

	for (int i = prime.size() - 1; i >= 0; i--) {
		int sum = 0;

		for (int j = i; j >= 0; j--) {
			sum += prime[j];
			if (sum > N) break;
			else if (sum == N) {
				answer++;
				break;
			}
		}
	}

	cout << answer << "\n";
}