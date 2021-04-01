#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> cards;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		cards.push(num);
	}

	int sum = 0;
	while (cards.size() != 1)
	{
		int n1 = cards.top();
		cards.pop();
		int n2 = cards.top();
		cards.pop();

		sum += (n1 + n2);
		cards.push(n1 + n2);
	}

	cout << sum << "\n";
}