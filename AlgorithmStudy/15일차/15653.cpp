#include <iostream>
#include <vector>

using namespace std;

int N, M;
int rx, ry, bx, by;
char map[10][10];

void moveUp() {
	char temp[10][10];
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			temp[y][x] = map[y][x];
		}
	}

	
}

void moveDown() {

}

void moveLeft() {

}

void moveRight() {

}

void escapeBall() {
	
}

int main() {
	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}


}