#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int T, M;
vector<int> v;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> T;

	// 풀이 1
	// 우선순위큐에 저장해 중간값이 나올 때까지 꺼내기

	//for (int i = 0; i < T; i++) {
	//	cin >> M;
	//	v.resize(M);

	//	for (int i = 0; i < M; i++) cin >> v[i];

	//	cout << (int)ceil(M / 2.0) << "\n";
	//	for (int i = 0; i < M; i += 2) {
	//		priority_queue<int> pq;

	//		for (int j = 0; j <= i; j++) pq.push(v[j]);

	//		for (int j = 0; j < (int)floor(i / 2.0); j++) {
	//			pq.pop();
	//		}

	//		cout << pq.top() << " ";
	//	}
	//	cout << "\n";
	//}

	// 풀이 2
	// 최소힙과 최대힙을 이용한 중간값 구하기

	for (int i = 0; i < T; i++) {
		cin >> M;
		
		priority_queue<int, vector<int>, greater<int>> minq;
		priority_queue<int, vector<int>, less<int>> maxq;

		v.resize(M);
		for (int i = 0; i < M; i++) {
			cin >> v[i];
		}

		cout << (int)ceil(M / 2.0) << "\n";

		for (int i = 0; i < M; i++) {
			if (minq.empty() && maxq.empty()) {
				maxq.push(v[i]);
			}
			else if (!maxq.empty() && minq.empty()) {
				if (maxq.top() < v[i]) {
					minq.push(v[i]);
				}
				else {
					minq.push(maxq.top());
					maxq.pop();
					maxq.push(v[i]);
				}
			}
			else {
				if (maxq.size() > minq.size()) {
					if (maxq.top() < v[i]) {
						minq.push(v[i]);
					}
					else {
						minq.push(maxq.top());
						maxq.pop();
						maxq.push(v[i]);
					}
				}
				else {
					if (maxq.top() < v[i]) {
						minq.push(v[i]);
						maxq.push(minq.top());
						minq.pop();
					}
					else {
						maxq.push(v[i]);
					}
				}
			}

			if (i % 2 == 0) {
				cout << maxq.top() << " ";
			}
		}
		cout << "\n";
	}
}

// max queue의 top은 중앙값
// max queue에는 중앙값보다 작은 녀석이 들어가야겠지
// min queue에는 중앙값보다 큰 녀석이 들어가야겠지