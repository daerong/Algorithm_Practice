#include <iostream>
#include <queue>

using namespace std;

#define MAX 100

int N;
int nApple;
int nTurn;
int result = 0;

int board[MAX][MAX];
pair<int, char> *table;
int table_index = 0;

typedef struct LOCATE {
	int x;
	int y;
} LOCATE;
queue<LOCATE> q;

// U, R, D, L
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int nHeadX = 0;
int nHeadY = 0;

void input() {
	cin >> N;
	cin >> nApple;
	for (int i = 0; i < nApple; i++) {
		int col, row;
		cin >> col >> row;
		board[col - 1][row - 1] = 9;
	}
	cin >> nTurn;
	table = new pair<int, char>[nTurn];
	for (int i = 0; i < nTurn; i++) {
		cin >> table[i].first >> table[i].second;
	}
}
//
//void input_check() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << board[i][j];
//		}
//		cout << endl;
//	}
//}

bool crush_wall(int nX, int nY) {
	if (nX >= N) return true;
	else if (nX < 0) return true;

	if (nY >= N) return true;
	else if (nY < 0) return true;

	return false;
}

bool crush_apple(int nX, int nY) {
	if (board[nY][nX] == 9) return true;

	return false;
}

bool crush_body(int nX, int nY) {
	if (board[nY][nX] == 1) return true;

	return false;
}

int change_dir(int dir) {
	if (table[table_index].second == 'D') {
		dir += 1;
		if (dir == 4) dir = 0;
	}
	else if (table[table_index].second == 'L') {
		dir -= 1;
		if (dir == -1) dir = 3;
	}

	table_index += 1;

	return dir;
}

void move(int hx, int hy, int dir) {
	if (table_index >= nTurn) {}
	else if (table[table_index].first == result) dir = change_dir(dir);

	result += 1;

	nHeadX += dx[dir];
	nHeadY += dy[dir];

	if (crush_wall(nHeadX, nHeadY)) return;		// º®¿¡ ºÎµúÈû

	if (crush_body(nHeadX, nHeadY)) return;		// ¸ö¿¡ ºÎµúÈû

	if (!crush_apple(nHeadX, nHeadY)) {				// »ç°ú ¸ø¸ÔÀ½
		LOCATE temp = q.front();
		board[temp.y][temp.x] = 0;
		//cout << "pop : (" << temp.x << ", " << temp.y << ")" << endl;
		q.pop();
	}

	q.push({ nHeadX, nHeadY });
	board[nHeadY][nHeadX] = 1;
	//cout << "push : (" << nHeadY << ", " << nHeadX << ")" << endl;

	//input_check();

	move(nHeadX, nHeadY, dir);
}

void solve() {
	input();
	board[0][0] = 1;
	q.push({ nHeadX, nHeadY });
	move(nHeadX, nHeadY, 1);
	cout << result;
}

int main() {
	solve();
	return 0;
}