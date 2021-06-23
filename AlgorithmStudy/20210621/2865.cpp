#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<float> v;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> N >> M >> K;

	v.resize(N);

	// 그리디 알고리즘
	// 각 참가자의 장르별
	// 최대 점수를 선택하면 능력의 합이 최대가 됨
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int n; float score;
			cin >> n >> score;

			v[n - 1] = max(v[n - 1], score);
		}
	}

	// 내림차순 정렬
	sort(v.begin(), v.end(), greater<float>());

	float sum = 0;
	for (int i = 0; i < K; i++) {
		sum += v[i];
	}
	cout.precision(1); // 소수점 설정
	cout << fixed << sum << "\n"; // std::fixed: format specifier
}