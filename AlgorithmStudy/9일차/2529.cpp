#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> numbers = { true, true, true, true, true, true, true, true, true, true };
vector<char> signs;
vector<int> answer;
vector<int> maxNum;
vector<int> minNum;

int k;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool promising(int n) {
	// 고른 값이 앞서 고른 수와 sign이 맞는지 확인
	for (int i = 0; i < n; i++) {
		if (signs[i] == '<') {
			if (answer[i] > answer[i + 1]) return false;
		}

		if (signs[i] == '>') {
			if (answer[i] < answer[i + 1]) return false;
		}
	}

	return true;
}

bool maxcmp(vector<int> num) {
	if (maxNum.size() == 0) return true;

	for (int i = 0; i < maxNum.size(); i++) {
		if (num[i] > maxNum[i]) return true;
	}

	return false;
}

bool mincmp(vector<int> num) {
	if (minNum.size() == 0) return true;

	for (int i = 0; i < minNum.size(); i++) {
		if (num[i] > minNum[i]) return false;
	}

	return true;
}

void choose_number(int n) {
	if (n >= k + 1) {
		if (maxcmp(answer)) maxNum = answer;
		if (mincmp(answer)) minNum = answer;

		return;
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i]) {
			answer[n] = i;
			numbers[i] = false;
			if (promising(n)) choose_number(n + 1);
			numbers[i] = true;
		}
	}
}

int main() {
	init();

	cin >> k;

	for (int i = 0; i < k; i++) {
		char sign;
		cin >> sign;
		signs.push_back(sign);
	}

	answer.resize(k + 1);

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i]) {
			answer[0] = i;
			numbers[i] = false;
			choose_number(1);
			numbers[i] = true;
		}
	}

	for (int i = 0; i < k + 1; i++)
		cout << maxNum[i];
	cout << "\n";

	for (int i = 0; i < k + 1; i++)
		cout << minNum[i];
	cout << "\n";

}