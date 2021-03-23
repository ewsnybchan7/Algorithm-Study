#include <iostream>
#include <string>

using namespace std;

int main() {
	while (1)
	{
		string s;
		int sLetter = 0, lLetter = 0, number = 0, blank = 0;

		getline(cin, s);

		for (int i = 0; i < s.size(); i++) {
			char c = s[i];

			if (c == ' ') blank++;
			else if (c >= 'A' && c <= 'Z') lLetter++;
			else if (c >= 'a' && c <= 'z') sLetter++;
			else number++;
		}

		if (sLetter + lLetter + number + blank)
			cout << sLetter << " " << lLetter << " " << number << " " << blank << "\n";
		else break;
	}
}