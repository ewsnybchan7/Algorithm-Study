#include <iostream>
#include <string>

using namespace std;

int T;

int main() {
	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++) {
		string s;
		getline(cin, s);

		int first = 0;
		int last = 0;
		while(last < s.size())
		{
			last = s.find(' ', first);
			string sub = s.substr(first, last - first);
			for (int k = sub.size() - 1; k >= 0; k--) {
				cout << sub[k];
			}
			cout << " ";

			first = last + 1;
		}
		cout << "\n";
	}
}