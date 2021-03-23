#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, check = 0;
stack<int> nums;
vector<int> result;
vector<char> operators;

void popNumber() {
	if (nums.size() == 0) return;

	if (nums.top() == result[check]) {
		nums.pop();
		operators.push_back('-');
		check++;

		popNumber();
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		result.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		nums.push(i + 1);
		operators.push_back('+');

		popNumber();
	}

	if (nums.empty()) {
		for (int i = 0; i < operators.size(); i++) {
			cout << operators[i] << "\n";
		}
	}
	else {
		cout << "NO" << "\n";
	}
}