#include <iostream>
#include <queue>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	int N, data;
	queue<int> q;
	
	cin >> N;

	while (true)
	{
		cin >> data;

		if (data == -1) break;
		else if (data == 0) q.pop();
		else {
			if (q.size() >= N) continue;
			else q.push(data);
		}
	}

	if (q.empty()) cout << "empty" << "\n";
	else {
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";
	}
}