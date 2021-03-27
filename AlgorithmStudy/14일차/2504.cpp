#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<char> parenthesis;
stack<int> pstack;
bool impossible = false;

int main() {
	char a[30];
	cin.getline(a, 30);

	for (int i = 0; i < 30; i++) {
		if (a[i]) parenthesis.push_back(a[i]);
		else break;
	}

	for (int i = 0; i < parenthesis.size(); i++) {
		if (impossible) break;
		
		if (parenthesis[i] == '(') {
			pstack.push(-1);
		}
		else if(parenthesis[i] == '[') {
			pstack.push(-2);
		}
		else if (parenthesis[i] == ')') {
			int sum = 0;

			if (pstack.empty()) {
				impossible = true;
				break;
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
					impossible = true;
					break;
				}
				else if (top > 0) {
					sum += top;
				}
			}
		}
		else if(parenthesis[i] == ']') {
			int sum = 0;

			if (pstack.empty()) {
				impossible = true;
				break;
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
					impossible = true;
					break;
				}
				else if (top > 0) {
					sum += top;
				}
			}
		}
		else {
			impossible = true;
		}
	}
	
	int sum = 0;

	while (!pstack.empty() && !impossible)
	{
		if (pstack.top() < 0) {
			impossible = true; 
			break;
		}
		sum += pstack.top();
		pstack.pop();
	}

	if (impossible)
	{
		cout << 0 << "\n";
	}
	else {
		cout << sum << "\n";
	}
}