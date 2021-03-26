#include <iostream>
#include <vector>

using namespace std;

int N, K;
int n = 0;
vector<bool> isPrime;
vector<int> answer;

void findPrimeNumber() {
	int prime = 0;

	for (int i = 2; i < N + 1; i++) {
		if (!isPrime[i]) {
			prime = i;
			break;
		}
	}
	
	int i = prime;
	while (i <= N)
	{
		if (isPrime[i]) {
			i += prime;
			continue;
		}

		isPrime[i] = true;
		answer.push_back(i);
		i += prime;
	}
}

int main() {
	cin >> N >> K;

	isPrime.resize(N + 1);

	while (answer.size() != N - 1)
	{
		findPrimeNumber();
	}

	cout << answer[K - 1] << "\n";
}