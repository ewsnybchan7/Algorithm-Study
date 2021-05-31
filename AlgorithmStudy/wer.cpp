#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <istream>
#include <fstream>

using namespace std;

float wer(vector<string> r, vector<string> h)
{
	//이차원배열 r,h 1만큼 크게 만든다음, 인덱싱
	vector<vector<int>>d(r.size() + 1, vector<int>(h.size() + 1, 0));
	for (int i = 0; i < r.size() + 1; i++)
	{
		for (int j = 0; j < h.size() + 1; j++)
		{
			if (i == 0) d[0][j] = j;
			else if (j == 0) d[i][0] = i;
		}
	}

	for (int i = 1; i < r.size() + 1; i++)
	{
		for (int j = 1; j < h.size() + 1; j++)
		{
			if (r[i - 1] == h[j - 1]) d[i][j] = d[i - 1][j - 1];
			else {
				int substitution = d[i - 1][j - 1] + 1;
				int insertion = d[i][j - 1] + 1;
				int deletion = d[i - 1][j] + 1;
				d[i][j] = min({ substitution, insertion, deletion });
			}
		}
	}

	return d[r.size()][h.size()];
}

int main() {
	string str_buf;
	ifstream ifs("WER2.csv");
	vector<string> REF, HYP;
	int i = 0;
	while (!ifs.eof()) {
		getline(ifs, str_buf, '\n');
		istringstream iss(str_buf);
		for (int i = 0; i < 3; i++)
		{
			string a;
			getline(iss, a, ',');
			switch (i)
			{
			case 0: i++;  break;
			case 1: REF.push_back(a); i++;  break;
			case 2: HYP.push_back(a); i = 0;  break;

			}
		}
	}
	cout << "file read complete" << endl;
	ifs.close();

	for (int k = 0; k < 26; k++)
	{

		string r = REF[k];
		string h = HYP[k];

		vector<string> rv, rh;
		rv.clear(); rh.clear();
		istringstream ss(r);
		string strBuffer;
		while (getline(ss, strBuffer, ' ')) {
			rv.push_back(strBuffer);
		}
		strBuffer.clear();
		istringstream sss(h);
		while (getline(sss, strBuffer, ' ')) {
			rh.push_back(strBuffer);
		}
		cout << wer(rv, rh) / float(rv.size()) * 100 << endl;
	}
}