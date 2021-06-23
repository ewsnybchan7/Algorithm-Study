#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> staff;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		staff.push_back(n);
	}
	sort(staff.begin(), staff.end());
	
	int n = 1;
	long long low = 0;
	long long high = 1000000000000LL;

	while (low + 1 < high)
	{
		long long mid = (low + high) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++) {
			sum += mid / staff[i];
		}

		if (sum >= M) high = mid;
		else low = mid;
	}
	cout << high << "\n";
}