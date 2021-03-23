#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> pipe;
int num = 0;

int main() {
	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		switch (s[i])
		{
		case '(':
			pipe.push(s[i]);
			break;
		case ')':
			char prev = s[i - 1];
			if (prev == '(') {
				pipe.pop();
				num += pipe.size();
			}
			else {
				pipe.pop();
				num += 1;
			}
			break;
		}
	}

	cout << num << endl;
}