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
	queue<int> q; // 라우터의 패킷 처리 방식과 큐의 데이터 저장 방식이 같음
	
	cin >> N;

	while (true)
	{
		cin >> data;

		if (data == -1) break;	// -1 까지 입력을 받음
		else if (data == 0) q.pop();	// 0 일 경우, 데이터를 pop
		else {
			if (q.size() >= N) continue; // 허용 크기를 넘길 경우, 패킷을 저장하지 못함.
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