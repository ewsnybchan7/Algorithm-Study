#include <iostream>
#include <algorithm>

using namespace std;

int maxHeap[200000];
int maxSize = 0;
int N;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void push(int x) {
	maxHeap[maxSize] = x;

	int index = maxSize;
	int parent = (maxSize - 1) / 2;

	while (index > 0)
	{
		if (maxHeap[parent] < maxHeap[index]) {
			swap(maxHeap[parent], maxHeap[index]);
			index = parent;
			parent = (index - 1) / 2;
		}
		else break;
	}

	maxSize++;
}

int pop() {
	if (maxSize == 0) return 0;

	swap(maxHeap[0], maxHeap[--maxSize]);

	int index = 0;

	while (++index < maxSize) {
		if (index + 1 < maxSize && maxHeap[index] < maxHeap[index + 1])
			index++;

		if (maxHeap[(index - 1) / 2] < maxHeap[index]) {
			swap(maxHeap[(index - 1) / 2], maxHeap[index]);
			index *= 2;
		}
	}

	return maxHeap[maxSize];
}

int main() {
	init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		switch (x)
		{
		case 0:
			cout << pop() << "\n";
			break;
		default:
			push(x);
			break;
		}
	}
}