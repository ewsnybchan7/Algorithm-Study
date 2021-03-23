#include <iostream>
#include <string>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

const int CHANNEL = 100;

string N;
int M;
bool button[10];
int pushed = 0;
vector<int> indexes;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool checkCorrect(int num) {
	char temp[10] = { 0, };
	sprintf(temp, "%d", num);
	string s = temp;

	for (int i = 0; i < s.size(); i++) {
		if (!button[s[i] - '0']) return false;
	}

	return true;
}

int main() {
	init();

	cin >> N;
	cin >> M;

	for (int i = 0; i < 10; i++) button[i] = true;

	for (int i = 0; i < M; i++) {
		int error;
		cin >> error;
		button[error] = false;
	}

	for (int i = 0; i < N.size(); i++) {
		if (button[N[i] - '0']) {
			pushed++;
		}
		else {
			indexes.push_back(i);
		}
	}

	int maxcheck = 0;
	int mincheck = 0;

	for (int check = N[0] - '0'; check < 9; maxcheck++) {
		if (button[check++])
			break;
	}
	for (int check = N[0] - '0'; check > 1; mincheck++) {
		if (button[--check])
			break;
	}

	int maxNum = stoi(N);
	int minNum = stoi(N);

	if (maxcheck < mincheck) {
		while (!checkCorrect(++maxNum));
		char temp[10] = { 0, };
		sprintf(temp, "%d", maxNum);
		string s = temp;
		
		cout << s.size() + maxNum - stoi(N) << "\n";
	}
	else if (maxcheck == mincheck) {
		while (!checkCorrect(++maxNum));
		while (minNum > 0 && !checkCorrect(--minNum));

		char temp[10] = { 0, };
		if (stoi(N) - minNum < maxNum - stoi(N)) {
			sprintf(temp, "%d", minNum);
			string s = temp;
			cout << s.size() + stoi(N) - minNum << "\n";
		}
		else {
			sprintf(temp, "%d", maxNum);
			string s = temp;
			cout << s.size() + maxNum - stoi(N) << "\n";
		}
	}
	else if (maxNum == CHANNEL) cout << 0 << "\n";
	else {
		while (minNum > 0 && !checkCorrect(--minNum));
		char temp[10] = { 0, };
		sprintf(temp, "%d", minNum);
		string s = temp;
		cout << s.size() + stoi(N) - minNum << "\n";
	}
}