#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_CHANNEL = 1000001;

int N, M;
vector<int> broken;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

bool isValid(int n) {
	if (n == 0) {
		if (find(broken.begin(), broken.end(), 0) == broken.end())
			return true;
		else
			return false;
	}

	while (n)
	{
		if (find(broken.begin(), broken.end(), n % 10) != broken.end())
			return false;

		n /= 10;
	}

	return true;
}

int getLength(int num) {
	if (num == 0) return 1;

	int len = 0;

	while (num)
	{
		num /= 10;
		len++;
	}

	return len;
}

int main() {
	init();

	cin >> N;
	cin >> M;
		
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		broken.push_back(num);
	}

	int result = MAX_CHANNEL * 2;
	int closer = 0;

	int maxNum = N;
	while (!isValid(maxNum) && maxNum < MAX_CHANNEL) {
		maxNum++;
	}
	int minNum = N;
	while (!isValid(minNum) && minNum >= 0) {
		minNum--;
	}

	int maxLength = maxNum < MAX_CHANNEL ? maxNum - N + getLength(maxNum) : MAX_CHANNEL * 2;
	int minLength = minNum >= 0 ? N - minNum + getLength(minNum) : MAX_CHANNEL * 2;

	int select = min(maxLength, minLength);
	cout << min(abs(N - 100), select) << "\n";
}