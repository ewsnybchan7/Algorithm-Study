#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<int> queue;

void push(int num);
int pop();
int size();
bool empty();
int front();
int back();

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
		else if (s == "front") {
			cout << front() << endl;
		}
		else if (s == "back") {
			cout << back() << endl;
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
	queue.push_back(num);
}

int pop() {
	if (empty()) return -1;

	int num = front();
	queue.erase(queue.begin());
	return num;
}

int size() {
	return queue.size();
}

bool empty() {
	return queue.empty();
}

int front() {
	if (empty()) return -1;

	return queue.front();
}

int back() {
	if (empty()) return -1;

	return queue.back();
}