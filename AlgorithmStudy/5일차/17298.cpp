#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N;
vector<int> number;
stack<int> NGE;
vector<int> answer;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		number.push_back(num);
		answer.push_back(-1);
	}

	for (int i = number.size() - 1; i >= 0; i--) {
		if (NGE.empty()) {
			answer[i] = -1;
			NGE.push(number[i]);
		}
		else {
			int top = NGE.top();
			while (!NGE.empty() && top <= number[i])
			{
				NGE.pop();
				if(!NGE.empty()) top = NGE.top();
			}

			if (NGE.empty()) {
				answer[i] = -1;
				NGE.push(number[i]);
			}
			else {
				answer[i] = top;
				NGE.push(number[i]);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	cout << endl;
}