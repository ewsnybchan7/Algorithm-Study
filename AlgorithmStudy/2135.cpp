#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

string RLE (string str){
	string temp = str;

	for (int len = 1; len <= temp.length() / 2; len++) {
		for (int i = 0; i < len; i++) {
			
			for (int j = i; j < temp.length();) {
				int start = j;
				int end = j + len > temp.length() ? temp.length() - j : len;

				string sub = temp.substr(j, end);
				char count = 0;
				
				while (sub == str.substr(j, end))
				{
					count++;
					end = j + len > str.length() ? str.length() - j : len;
					j += end;
				}

				if (count > 1) {
					string cntstr = "0";
					cntstr[0] = cntstr[0] + count;
					temp = str.substr(0, start) + cntstr + "(" + sub + ")" + str.substr(j, str.length() - j);
				
				}
			}
		}
	}
}

int main() {
	init();

	string str;

	cin >> str;

	RLE(str);
}
