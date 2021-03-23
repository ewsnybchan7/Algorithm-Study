#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int L;
string S;
// sa: suffix array / suffix array ���� �ε����� �����
// g: group number / ó������ ���ĺ��� ����ǰ� ���Ŀ��� �켱������ �����
// ng: new group number 
// 2^(n-1)�� ������ ��� �񱳸� �̹� �����߱� ������ 2^n���� ���� �� ���� ���ߴ� ������ ������ ������
// �켱������ ���� �� �ִ�.
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
			if (g[i] == g[j]) return g[i + len] < g[j + len]; // ������ ������ ó�� �켱����(ù ���ĺ�)�� ��
			else return g[i] < g[j];
		};

		sort(sa.begin(), sa.end(), cmp);
		ng[sa[0]] = 0; // suffix array�� �� ó���� �켱���� ù ��°
		ng[L] = -1; // �������� �� ���ܴ��

		// ���ο� group �켱���� ���ϱ�
		for (int i = 1; i < L; i++) {
			if (cmp(sa[i - 1], sa[i])) ng[sa[i]] = ng[sa[i - 1]] + 1; // suffix array�� �տ������� �ΰ��� ���Ͽ� �켱���� ���ϱ�
			else ng[sa[i]] = ng[sa[i - 1]]; // ���� �׷��̹Ƿ� ���� �켱����
		}
		g = ng;

		len <<= 1;
	}


	// LCP �˰���
	// 0 banana a
	// 1 anana  ana
	// 2 nana   anana
	// 3 ana    banana
	// 4 na     na
	// 5 a      nana
	// ana(S[3..])�� anana(S[1..])�� LCP�� 3�̴� �� �� na nana�� LCP�� ����Ϸ��� �� ��, 
	// ana�� anana�� LCP�� 3�̱� ������ a�� �̹� ���� na�� nana�� LCP�� �ּ� 2��� ���̴�.
	// ��, na�� �̹� ����߱� ������ ��ġ�� �� �κ��� �ٽ� ���� �ʿ䰡 ���ٴ� �ǹ̴�.

	// rank[i]: s[i..]�� ������(suffix array)���� �� ��° ���̻������� ��Ÿ����.
	// ex) rank[0]: banana�� suffix array���� 3��° ���̻��̴�.
	// rank[5]: a�� suffix array���� 0��° ���̻��̴�.
	vector<int> rank;
	rank.resize(L); lcp.resize(L);
	for (int i = 0; i < L; i++)
		rank[sa[i]] = i;
	
	int matched = 0;
	for (int i = 0; i < L; i++) {
		int k = rank[i]; // s[i..]�� �� ��° ���̻�����

		if (k) {
			int j = sa[k - 1]; // sa[k-1]: ���� ��° ���̻簡 ���ڿ����� �� ��° ���ĺ�����

			// �ش� �κ��� �˰����� �ٽ�
			// ������ ���� �ش� �ݺ����� ���鼭 2n���� �ݺ��ȴ� => O(n)
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