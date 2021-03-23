#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int L;
string S;
// sa: suffix array / suffix array 순의 인덱스가 저장됨
// g: group number / 처음에는 알파벳이 저장되고 이후에는 우선순위가 저장됨
// ng: new group number 
// 2^(n-1)개 단위로 끊어서 비교를 이미 진행했기 다음에 2^n에서 비교할 때 이전 비교했던 값으로 나머지 반절의
// 우선순위를 정할 수 있다.
vector<int> sa, g, ng;
vector<int> lcp; // LCP(Longest Common Prefix)

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> L;
	cin.ignore();
	getline(cin, S);

	sa.resize(L); g.resize(L + 1); ng.resize(L + 1);
	for (int i = 0; i < L; i++) sa[i] = i, g[i] = S[i];

	g[L] = -1;
	int len = 1;

	while (len < L) {
		auto cmp = [&](int i, int j) {
			if (g[i] == g[j]) return g[i + len] < g[j + len]; // 나머지 반절의 처음 우선순위(첫 알파벳)을 비교
			else return g[i] < g[j];
		};

		sort(sa.begin(), sa.end(), cmp);
		ng[sa[0]] = 0; // suffix array의 맨 처음은 우선순위 첫 번째
		ng[L] = -1; // 마지막은 비교 제외대상

		// 새로운 group 우선순위 정하기
		for (int i = 1; i < L; i++) {
			if (cmp(sa[i - 1], sa[i])) ng[sa[i]] = ng[sa[i - 1]] + 1; // suffix array의 앞에서부터 두개씩 비교하여 우선순위 정하기
			else ng[sa[i]] = ng[sa[i - 1]]; // 같은 그룹이므로 같은 우선순위
		}
		g = ng;

		len <<= 1;
	}


	// LCP 알고리즘
	// 0 banana a
	// 1 anana  ana
	// 2 nana   anana
	// 3 ana    banana
	// 4 na     na
	// 5 a      nana
	// ana(S[3..])와 anana(S[1..])의 LCP는 3이다 그 후 na nana의 LCP를 계산하려고 할 때, 
	// ana와 anana의 LCP가 3이기 때문에 a가 이미 없는 na와 nana의 LCP는 최소 2라는 것이다.
	// 즉, na를 이미 계산했기 때문에 겹치는 앞 부분을 다시 구할 필요가 없다는 의미다.

	// rank[i]: s[i..]가 사전상(suffix array)에서 몇 번째 접미사인지를 나타낸다.
	// ex) rank[0]: banana는 suffix array에서 3번째 접미사이다.
	// rank[5]: a는 suffix array에서 0번째 접미사이다.
	vector<int> rank;
	rank.resize(L); lcp.resize(L);
	for (int i = 0; i < L; i++)
		rank[sa[i]] = i;
	
	int matched = 0;
	for (int i = 0; i < L; i++) {
		int k = rank[i]; // s[i..]가 몇 번째 접미사인지

		if (k) {
			int j = sa[k - 1]; // sa[k-1]: 이전 번째 접미사가 문자열에서 몇 번째 알파벳인지

			// 해당 부분의 알고리즘의 핵심
			// 증명을 통해 해당 반복문을 돌면서 2n번만 반복된다 => O(n)
			while (S[j + matched] == S[i + matched])
				++matched;

			lcp[k] = matched;

			if (matched)
				--matched;
		}
	}

	int maxNum = 0;
	for (auto elem : lcp) {
		maxNum = max(maxNum, elem);
	}

	cout << maxNum << endl;
}