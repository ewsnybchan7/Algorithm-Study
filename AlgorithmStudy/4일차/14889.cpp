#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> players;
unsigned long long d[21][21] = {};

int N;
int minimum = 2147483647;

int main() {
	d[1][0] = 1;
	d[1][1] = 1;

	for (int i = 2; i <= 20; i++) {
		d[i][0] = 1;
		for (int j = 1; j <= 20; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
	}

	cin >> N;

	for (int y = 0; y < N; y++) {
		vector<int> p;
		for (int x = 0; x < N; x++) {
			int status;
			cin >> status;
			p.push_back(status);
		}
		players.push_back(p);
	}

	vector<int> numbers;
	for (int i = 0; i < N; i++) numbers.push_back(i);

	vector<int> ind;

	for (int i = 0; i < N / 2; i++)
		ind.push_back(1);

	for (int i = 0; i < N / 2; i++)
		ind.push_back(0);

	sort(ind.begin(), ind.end());

	int n = 0;
	do {
		vector<int> start;
		vector<int> link;
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i]) {
				start.push_back(numbers[i]);
			}
			else {
				link.push_back(numbers[i]);
			}
		}

		vector<int> p;
		for (int i = 0; i < 2; i++)
			p.push_back(1);
		for (int i = 0; i < start.size() - 2; i++)
			p.push_back(0);

		sort(p.begin(), p.end());

		int ssum = 0;
		int lsum = 0;

		do {
			int first = 0;
			int second = 0;

			for (int i = 0; i < p.size(); i++) {
				if (p[i]) {
					if (first == 0) first = start[i];
					else second = start[i];
				}
			}

			ssum += (players[first][second] + players[second][first]);

			first = 0;
			second = 0;

			for (int i = 0; i < p.size(); i++) {
				if (p[i]) {
					if (first == 0) first = link[i];
					else second = link[i];
				}
			}

			lsum += (players[first][second] + players[second][first]);
		} while (next_permutation(p.begin(), p.end()));
		minimum = minimum > abs(ssum - lsum) ? abs(ssum - lsum) : minimum;
	} while (n++ < d[N][N/2] / 2 && next_permutation(ind.begin(), ind.end()));

	cout << minimum << endl;
}
