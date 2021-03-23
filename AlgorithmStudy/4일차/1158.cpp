#include <iostream>
#include <vector>

using namespace std;

vector<int> josephus;
vector<int> answer;
int N, K;

int main() {
	cin >> N >> K;

	int index = -1;

	for (int i = 0; i < N; i++) {
		josephus.push_back(i + 1);
	}

	while (josephus.size()) {
		index = (index + K) % josephus.size();
		answer.push_back(josephus[index]);
		josephus.erase(josephus.begin() + index);
		index = index - 1 < 0 ? josephus.size() - 1 : (index - 1) % josephus.size();
	}

	cout << "<";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
		if (i < answer.size() - 1) cout << ", ";
	}
	cout << ">" << endl;
}
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> josephus;
//vector<int> answer;
//int N, K;
//
//int main() {
//	cin >> N >> K;
//
//	int index = -1;
//
//	for (int i = 0; i < N; i++) {
//		josephus.push_back(i + 1);
//	}
//
//	while (answer.size() != N) {
//		int num = 0;
//		while (num < K)
//		{
//			index = ++index % N;
//			if (josephus[index] != -1)
//				num++;
//		}
//		answer.push_back(josephus[index]);
//		josephus[index] = -1;
//	}
//
//	cout << "<";
//	for (int i = 0; i < answer.size(); i++) {
//		cout << answer[i];
//		if (i < answer.size() - 1) cout << ", ";
//	}
//	cout << ">" << endl;
//}