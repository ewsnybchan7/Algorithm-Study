#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int T;

unordered_set<string> markers;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> T;


	for (int i = 0; i < T; i++) {
		int n, m;
		string dna;
		string marker;
		int match = 0;

		cin >> n >> m;
		cin >> dna; cin.ignore();
		cin >> marker; cin.ignore();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m - i; j++) {
				string reverse;
				for (auto iter = marker.begin(); iter != marker.begin() + i; iter++)
					reverse.push_back(*iter);

				for (auto iter = marker.rbegin() + j; iter != marker.rend() - i; ++iter)
					reverse.push_back(*iter);

				for (int k = reverse.size(); k < m; k++)
					reverse.push_back(marker[k]);

				markers.insert(reverse);
			}
		}

		for (int i = 0; i < n - (m - 1); i++) {
			string sub = dna.substr(i, m);
			if (markers.find(sub) != markers.end()) match++;
		}

		cout << match << "\n";
		markers.clear();
	}
}