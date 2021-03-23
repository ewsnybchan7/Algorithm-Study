#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int L;
string S;
vector<int> sa, g, ng;
vector<int> lcp, r;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> L;
	cin.ignore();
	cin >> S;
	
	sa.resize(L); g.resize(L + 1); ng.resize(L + 1);
	for (int i = 0; i < L; i++) sa[i] = i, g[i] = S[i];

	g[L] = -1;

	int len = 1;
	while (len < S.size())
	{
		auto cmp = [&](int x, int y) {
			if (g[x] == g[y]) return g[x + len] < g[y + len];
			else return g[x] < g[y];
		};

		sort(sa.begin(), sa.end(), cmp);

		ng[L] = -1;
		ng[sa[0]] = 0;

		for (int i = 1; i < L; i++) {
			if (cmp(sa[i - 1], sa[i])) ng[sa[i]] = ng[sa[i - 1]] + 1;
			else ng[sa[i]] = ng[sa[i - 1]];
		}

		g = ng;

		len *= 2;
	}

	lcp.resize(L);
	r.resize(L);

	for (int i = 0; i < L; i++) {
		r[sa[i]] = i;
	}

	int temp = 0;
	for (int i = 0; i < L; i++) {
		int k = r[i];

		if (k != 0) {
			int j = sa[k - 1];

			while (S[i + temp] == S[j + temp]) temp++;

			lcp[k] = temp;

			if (temp) temp--;
		}
	}

	int maxNum = 0;
	for (int i = 0; i < L; i++) {
		maxNum = max(maxNum, lcp[i]);
	}

	cout << maxNum << "\n";
}

