#include <iostream>
#include <string>

using namespace std;

int check[26];
string S;

int main() {
	cin >> S;

	for (int i = 0; i < 26; i++)
		check[i] = -1;

	for (int i = 0; i < S.size(); i++) {
		int index = int(S[i]) - 97;
		if(check[index] == -1 || check[index] > i) check[index] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << check[i] << " ";
	}
}