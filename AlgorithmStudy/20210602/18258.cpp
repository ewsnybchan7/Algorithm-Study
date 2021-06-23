#include <iostream>

using namespace std;

// 큐를 구현하기
// vector의 erase는 컨테이너의 크기가 커질수록 시간복잡도가 증가
// 따라서 테스트를 완료하기 위해 erase를 사용하지 말고 컨테이너의 요소를 지울 수 있어야함
// 따라서 구현할 때 Linkedlist를 사용하는 것이 좋다
// 하지만 구현하기 귀찮기 때문에 인덱스를 옮기는 방법으로 구현
class Queue {
private:
	int start;
	int end;
	int qSize;
	int queue[2000000];

public:
	Queue() {
		start = 0;
		end = 0;
		qSize = 0;
	}

	void push(int X) {
		queue[end++] = X; // 큐는 컨테이너의 뒷부분부터 데이터를 넣는다
		qSize++;
	}

	int pop() {
		if (empty()) return -1;
		else {
			int temp = queue[start++]; // 큐는 컨테이너의 앞부분부터 삭제하기 때문에 start를 앞당긴다
			qSize--;
			return temp;
		}
	}

	int size() {
		return qSize;
	}

	bool empty() {
		if (qSize == 0) return true;
		else return false;
	}

	int front() {
		if (empty()) return -1;
		else return queue[start];
	}

	int back() {
		if (empty()) return -1;
		else return queue[end - 1];
	}
};

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	init();

	Queue q;
	int N;
	string s;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;

		if (s == "push") {
			int X;
			cin >> X;
			q.push(X);
		}
		else if (s == "pop") cout << q.pop() << "\n";
		else if (s == "size") cout << q.size() << "\n";
		else if (s == "empty") cout << q.empty() << "\n";
		else if (s == "front") cout << q.front() << "\n";
		else cout << q.back() << "\n";
	}
}
