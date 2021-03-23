#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<int> stack;

void push(int num);
int pop();
int top();
int size();
bool empty();

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string s = "";
		
		cin >> s;

		if (s == "push") {
			int num;
			cin >> num;
			push(num);
		}
		else if(s == "top") {
			cout << top() << endl;
		}
		else if (s == "size") {
			cout << size() << endl;
		}
		else if (s == "empty") {
			cout << empty() << endl;
		}
		else if (s == "pop") {
			cout << pop() << endl;
		}
	}
}

void push(int num) {
	stack.push_back(num);
}

int pop() {
	if (stack.empty()) return -1;

	int num = stack.back();
	stack.pop_back();
	return num;
}

int top() {
	if (stack.empty()) return -1;

	return stack.back();
}

int size()
{
	return stack.size();
}

bool empty()
{
	return stack.empty();
}
