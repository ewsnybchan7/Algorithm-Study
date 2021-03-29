#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;

bool check[10000];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void countDSLR(int init, int target) {
	queue<pair<string, int>> q;
	q.push({ "", init });
	
	check[init] = true;

	while (!q.empty())
	{
		int num = q.front().second;
		string str = q.front().first;
		
		q.pop();

		if (num == target) {
			cout << str << "\n";
			return;
		}

		int nextNum = (num * 2) % 10000;
		if (!check[nextNum]) {
			check[nextNum] = true;
			q.push({ str + "D", nextNum });
		}

		nextNum = num - 1 < 0 ? 9999 : num - 1;
		if (!check[nextNum]) {
			check[nextNum] = true;
			q.push({ str + "S", nextNum });
		}

		nextNum = (num % 1000) * 10 + (num / 1000);
		if (!check[nextNum]) {
			check[nextNum] = true;
			q.push({ str + "L", nextNum });
		}

		nextNum = (num % 10) * 1000 + (num / 10);
		if (!check[nextNum]) {
			check[nextNum] = true;
			q.push({ str + "R", nextNum });
		}
	}
}

int main() {
	init();

	cin >> T;

	for (int t = 0; t < T; t++) {
		int A, B;
		cin >> A >> B;

		memset(check, false, sizeof(check));

		countDSLR(A, B);
	}
}