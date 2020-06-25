#include <iostream>

using namespace std;

int minn = 987654321;
int N, M;
char map[10][10];
pair<int, int> R, B;

// U, D, L, R
int X_move[] = {0, 0, -1, 1};
int Y_move[] = {-1, 1, 0, 0};

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				R.first = i;
				R.second = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B')
			{
				B.first = i;
				B.second = j;
				map[i][j] = '.';
			}
		}
	}
}

void move(int Rx, int Ry, int Bx, int By, int dir, int cnt) {
	if (cnt >= minn) return;
	if (cnt > 10) return;

	bool R_Flag = false;
	bool B_Flag = false;

	int nRx = Rx;
	int nRy = Ry;

	while (true) {
		nRx = nRx + X_move[dir];
		nRy = nRy + Y_move[dir];

		if (map[nRx][nRy] == 'O') {
			R_Flag = true;
			break;
		}
		else if (map[nRx][nRy] == '#') {
			nRx = nRx - X_move[dir];
			nRy = nRy - Y_move[dir];
			break;
		}
	}

	int nBx = Bx;
	int nBy = By;

	while (true) {
		nBx = nBx + X_move[dir];
		nBy = nBy + Y_move[dir];

		if (map[nBx][nBy] == 'O') {
			B_Flag = true;
			break;
		}
		else if (map[nBx][nBy] == '#') {
			nBx = nBx - X_move[dir];
			nBy = nBy - Y_move[dir];
			break;
		}
	}

	if (B_Flag) return;

	if (nRx == nBx && nRy == nBy) {
		if (abs(Rx - nRx + Ry - nRy) > abs(Bx - nBx + By - nBy)) {
			nRx = nRx - X_move[dir];
			nRy = nRy - Y_move[dir];
		}
		else {
			nBx = nBx - X_move[dir];
			nBy = nBy - Y_move[dir];
		}
	}

	if (R_Flag) {
		if (minn > cnt) {
			minn = cnt;
		}
		return;
	}


	switch (dir) {
	case 0:
		move(nRx, nRy, nBx, nBy, 2, cnt + 1);
		move(nRx, nRy, nBx, nBy, 3, cnt + 1);
	case 1:
		move(nRx, nRy, nBx, nBy, 2, cnt + 1);
		move(nRx, nRy, nBx, nBy, 3, cnt + 1);
	case 2:
		move(nRx, nRy, nBx, nBy, 0, cnt + 1);
		move(nRx, nRy, nBx, nBy, 1, cnt + 1);
	case 3:
		move(nRx, nRy, nBx, nBy, 0, cnt + 1);
		move(nRx, nRy, nBx, nBy, 1, cnt + 1);
	}
}

void Solution() {
	for (int i = 0; i < 4; i++) {
		int x = R.first;
		int y = R.second;
		int xx = B.first;
		int yy = B.second;

		move(x, y, xx, yy, i, 1);
	}

	if (minn > 10 || minn == 987654321) minn = -1;
	cout << minn << endl;
}

int main() {

	input();
	Solution();


	return 0;
}