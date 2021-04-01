#include <iostream>
#include <vector>

using namespace std;

int A, B, m;
vector<int> num;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	cin >> A >> B;
	cin >> m;

	num.resize(m);

	for (int i = 0; i < m; i++)
		cin >> num[i];

	int decimal = 0;
	int pow = 1;
	for (int i = m - 1; i >= 0; i--, pow *= A) {
		decimal += num[i] * pow;
	}

	vector<int> change;
	while (decimal != 0)
	{
		int remainder = decimal % B;
		change.push_back(remainder);
		decimal /= B;
	}

	for (auto iter = change.rbegin(); iter != change.rend(); iter++)
		cout << (*iter) << " ";
	cout << "\n";
}