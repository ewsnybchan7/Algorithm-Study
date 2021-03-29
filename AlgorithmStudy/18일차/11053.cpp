#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> answer;

int main() {
	cin >> N;

	A.resize(N); answer.resize(N + 1);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int maxCount = 0;
	for (int i = 0; i < N; i++) {
		int count = 0;

		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				count = max(count, answer[j + 1]);
			}
		}

		answer[i + 1] = count + 1;
		maxCount = max(maxCount, answer[i + 1]);
	}

	cout << maxCount << "\n";
}