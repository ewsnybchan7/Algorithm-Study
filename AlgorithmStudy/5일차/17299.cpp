#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<pair<int, int>> F;
stack<pair<int, int>> NGF;
vector<int> answer;

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
		A.push_back(num);
		answer.push_back(-1);
	}

	F.resize(1000000);

	for (int i = 0; i < 1000000; i++) {
		F[i] = make_pair(i + 1, 0);
	}

	for (int i = 0; i < N; i++) {
		F[A[i] - 1].second += 1;
	}

	for (int i = A.size() - 1; i >= 0; i--) {
		if (NGF.empty()) {
			answer[i] = -1;
			NGF.push(F[A[i] - 1]);
		}
		else {
			pair<int, int> top = NGF.top();

			while (!NGF.empty() && (top.first == F[A[i] - 1].first || top.second <= F[A[i] - 1].second)) {
				NGF.pop();
				if (!NGF.empty()) top = NGF.top();
			}

			if (NGF.empty()) {
				answer[i] = -1;
				NGF.push(F[A[i] - 1]);
			}
			else {
				answer[i] = top.first;
				NGF.push(F[A[i] - 1]);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	cout << endl;
}
//3 3 2 1 1 2 3
//
//-1 -1 3 2 2 3 -1
//-1 -1 1 2 2 1 -1