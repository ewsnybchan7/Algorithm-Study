#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string parenthesis;
stack<int> pstack;
bool impossible = false;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> parenthesis;

	for (int i = 0; i < parenthesis.size(); i++) {
		if (parenthesis[i] == '(') pstack.push(-1);
		else if(parenthesis[i] == '[') pstack.push(-2);
		else if (parenthesis[i] == ')') {
			int sum = 0;

			if (pstack.empty()) {
				cout << 0 << "\n";
				return 0;
			}

			while (!pstack.empty()) {
				int top = pstack.top();
				pstack.pop();
				if (top == -1) {
					!sum ? sum = 2 : sum *= 2;
					pstack.push(sum);
					break;
				}
				else if (top == -2) {
					cout << 0 << "\n";
					return 0;
				}
				else if (top > 0) {
					sum += top;
				}
			}
		}
		else if(parenthesis[i] == ']') {
			int sum = 0;

			if (pstack.empty()) {
				cout << 0 << "\n";
				return 0;
			}

			while (!pstack.empty()) {
				int top = pstack.top();
				pstack.pop();
				if (top == -2) {
					!sum ? sum = 3 : sum *= 3;
					pstack.push(sum);
					break;
				}
				else if (top == -1) {
					cout << 0 << "\n";
					return 0;
				}
				else if (top > 0) {
					sum += top;
				}
			}
		}
		else {
			cout << 0 << "\n";
			return 0;
		}
	}
	
	int sum = 0;

	while (!pstack.empty())
	{
		if (pstack.top() < 0) {
			cout << 0 << "\n";
			return 0;
		}
		sum += pstack.top();
		pstack.pop();
	}

	cout << sum << "\n";
}