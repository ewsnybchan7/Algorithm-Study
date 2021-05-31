//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//vector<vector<char>> map;
//int check[30][30][4];
//
//int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
//int R, C;
//
//struct Data
//{
//	int x, y, dir, count;
//};
//
//bool isValid(int x, int y) {
//	if (x < 0 || x >= C) return false;
//	if (y < 0 || y >= R) return false;
//	if (map[y][x] == '*') return false;
//	return true;
//}
//
//void mirror(int sx, int sy, int d, int c) {
//	queue<Data> pq;
//	pq.push({ sx, sy, d, c });
//	
//	while (!pq.empty())
//	{
//		Data output = pq.front();
//		pq.pop();
//
//		int cx = output.x + dir[output.dir][0];
//		int cy = output.y + dir[output.dir][1];
//
//		if (!isValid(cx, cy)) continue;
//
//		if (map[cy][cx] == 'P') {
//			if (output.dir == 0 || output.dir == 1) {
//
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> R >> C;
//
//	for (int i = 0; i < R; i++) {
//		vector<char> s;
//		for (int j = 0; j < C; j++) {
//			char c;
//			cin >> c;
//			s.push_back(c);
//		}
//		map.push_back(s);
//	}
//
//	for (int i = 0; i < 4; i++) {
//		mirror(0, 0, i, 0);
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int gram;
//vector<int> num = { 1, 3, 7, 26, 94, 259 };
//vector<int> leftScale;
//vector<int> rightScale;
//bool correct = false;
//
//void search(int n) {
//	if (n == 6) {
//		int lsum = 0;
//		for (int i = 0; i < leftScale.size(); i++) {
//			lsum += leftScale[i];
//		}
//
//		int rsum = 0;
//		for (int i = 0; i < rightScale.size(); i++) {
//			rsum += rightScale[i];
//		}
//
//		cout << "\n";
//		if (rsum == lsum) {
//			for (int i = 0; i < leftScale.size(); i++) {
//				cout << leftScale[i] << " ";
//			}
//
//			cout << "0 ";
//			for (int i = 0; i < rightScale.size(); i++) {
//				cout << rightScale[i] << " ";
//			}
//			cout << "\n";
//			correct = true;
//		}
//
//		return;
//	}
//
//	leftScale.push_back(num[n]);
//	search(n + 1);
//	if (correct) return;
//	leftScale.pop_back();
//
//	rightScale.push_back(num[n]);
//	search(n + 1);
//	if (correct) return;
//	rightScale.pop_back();
//
//	search(n + 1);
//	if (correct) return;
//}
//
//
//int main() {
//	cin >> gram;
//	leftScale.push_back(gram);
//
//	search(0);
//
//	if (!correct) cout << gram << "\n";
//
//	return 0;
//}

