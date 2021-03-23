#include <iostream>
#include <math.h>

using namespace std;

int maxHeap[100000];
int minHeap[100000];
int maxSize = 0;
int minSize = 0;

int N;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void push(int x) {
	if (x < 0) {
		maxHeap[maxSize] = x;

		int index = maxSize;
		int parent = maxHeap[(maxSize - 1) / 2];
		int child = maxHeap[maxSize];

		while (index > 0 && parent < child)
		{
			swap(maxHeap[(index - 1) / 2], maxHeap[index]);
			index = (index - 1) / 2;
			parent = maxHeap[(index - 1) / 2];
			child = maxHeap[index];
		}

		maxSize++;
	}
	else {
		minHeap[minSize] = x;

		int index = minSize;
		int parent = minHeap[(minSize - 1) / 2];
		int child = minHeap[minSize];

		while (index > 0 && parent > child)
		{
			swap(minHeap[(index - 1) / 2], minHeap[index]);
			index = (index - 1) / 2;
			parent = minHeap[(index - 1) / 2];
			child = minHeap[index];
		}

		minSize++;
	}
}

int max_pop() {
	swap(maxHeap[--maxSize], maxHeap[0]);

	int index = 0;
	int parent = maxHeap[index];
	int left = maxHeap[(index + 1) * 2 - 1];
	int right = maxHeap[(index + 1) * 2];

	while (++index < maxSize)
	{
		if ((index + 1) < maxSize && left < right)
			index++;

		if (parent < maxHeap[index]) {
			swap(maxHeap[(index - 1) / 2], maxHeap[index]);
		}

		parent = maxHeap[index];
		index *= 2;
		left = maxHeap[index + 1];
		right = maxHeap[index + 2];
	}

	int temp = maxHeap[maxSize];
	maxHeap[maxSize] = 0;
	return temp;
}

int min_pop() {
	swap(minHeap[--minSize], minHeap[0]);

	int index = 0;
	int parent = minHeap[index];
	int left = minHeap[(index + 1) * 2 - 1];
	int right = minHeap[(index + 1) * 2];

	while (++index < minSize)
	{
		if ((index + 1) < minSize && left > right)
			index++;

		if (parent > minHeap[index]) {
			swap(minHeap[(index - 1) / 2], minHeap[index]);
		}

		parent = minHeap[index];
		index *= 2;
		left = minHeap[index + 1];
		right = minHeap[index + 2];
	}

	int temp = minHeap[minSize];
	minHeap[minSize] = 0;
	return temp;
}

int pop() {
	if (maxSize == 0 && minSize == 0) return 0;
	else if (maxSize == 0) return min_pop();
	else if (minSize == 0) return max_pop();

	if (abs(maxHeap[0]) <= abs(minHeap[0])) {
		return max_pop();
	}
	else {
		return min_pop();
	}
}

int main() {
	init();
	cin >> N;

	for (int t = 0; t < N; t++) {
		int num;
		cin >> num;
		switch (num)
		{
		case 0:
			cout << pop() << "\n";
			break;
		default:
			push(num);
			break;
		}
	}
}