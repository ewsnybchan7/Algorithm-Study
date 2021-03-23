#include <iostream>
#include <string>
#include <stack>

using namespace std;

string result;
stack<char> operations;

int main() {
	string s;

	while (getline(cin, s) && s.length() != 0) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				result.push_back(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-') {
				while (!operations.empty()) {
					char top = operations.top();
					if (top == '+' || top == '-' || top == '*' || top == '/') {
						result.push_back(top);
						operations.pop();
					}
					else break;
				}

				operations.push(s[i]);
			}
			else if (s[i] == '*' || s[i] == '/') {
				while (!operations.empty()) {
					char top = operations.top();
					if (top == '*' || top == '/') {
						result.push_back(top);
						operations.pop();
					}
					else break;
				}

				operations.push(s[i]);
			}
			else if(s[i] == '(') {
				operations.push(s[i]);
			}
			else {
				while (operations.top() != '(')
				{
					char top = operations.top();
					operations.pop();
					result.push_back(top);
				}
				operations.pop();
			}
		}
	}

	while (!operations.empty())
	{
		char top = operations.top();
		operations.pop();
		result.push_back(top);
	}

	cout << result << endl;
}