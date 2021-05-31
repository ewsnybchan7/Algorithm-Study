#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> jewel;
vector<int> backpack;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}



int main() {
	init();

	cin >> N >> K;

	jewel.resize(N);
	backpack.resize(K);

	for (int i = 0; i < N; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}

	for (int i = 0; i < K; i++) {
		cin >> backpack[i];
	}
}
