#include <iostream>

using namespace std;

int N = 0;		// 지도의 세로
int M = 0;		// 지도의 가로
int x = 0;		// 주사위 세로 위치
int y = 0;		// 주사위 가로 위치

int nIns = 0;	// 명령어의 갯수

int map[20][20];
int ins[1000];

int s1 = 0;		// 위
int s2 = 0;		// 북
int s3 = 0;		// 동
int s4 = 0;		// 서
int s5 = 0;		// 남
int s6 = 0;		// 밑

void input();

void change_side(int type) {
	int temp = 0;
	switch (type) {
	case 1:			// R
		temp = s3;
		s3 = s1;
		s1 = s4;
		s4 = s6;
		s6 = temp;
		break;
	case 2:			// L
		temp = s4;
		s4 = s1;
		s1 = s3;
		s3 = s6;
		s6 = temp;
		break;
	case 3:			// U
		temp = s2;
		s2 = s1;
		s1 = s5;
		s5 = s6;
		s6 = temp;
		break;
	case 4:			// D
		temp = s5;
		s5 = s1;
		s1 = s2;
		s2 = s6;
		s6 = temp;
		break;
	}
}

bool change_locate(int type) {
	switch (type) {
	case 1:
		x += 1;
		if (x >= M) {
			x -= 1;
			return false;
		}
		break;
	case 2:
		x -= 1;
		if (x < 0) {
			x += 1;
			return false;
		}
		break;
	case 3:
		y -= 1;
		if (y < 0) {
			y += 1;
			return false;
		}
		break;
	case 4:
		y += 1;
		if (y >= N) {
			y -= 1;
			return false;
		}
		break;
	}
	return true;
}

void move() {
	for (int turn = 0; turn < nIns; turn++) {
		if (!change_locate(ins[turn])) {
			continue;
		}

		change_side(ins[turn]);

		if (map[y][x] == 0) {
			map[y][x] = s6;
		}
		else {
			s6 = map[y][x];
			map[y][x] = 0;
		}

		cout << s1 << endl;
	}

}

void solve() {
	input();
	move();
}

int main() {
	solve();
	return 0;
}

void input() {
	cin >> N >> M >> y >> x >> nIns;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	for (int i = 0; i < nIns; i++) {
		cin >> ins[i];
	}
}