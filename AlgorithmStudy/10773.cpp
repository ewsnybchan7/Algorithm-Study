#include <iostream>
#include <stack>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	stack<int> money;
	int K, n;
	
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> n;

		if (n == 0) money.pop();
		else money.push(n);
	}

	int answer = 0;
	while (!money.empty())
	{
		answer += money.top();
		money.pop();
	}

	cout << answer << "\n";
}
