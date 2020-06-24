#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 500

void input();

int result = 0;

int board[MAX][MAX];
int N = 0;		// 세로
int M = 0;		// 가로

int find_max(int n1, int n2, int n3, int n4, int n5, int n6) {
	int max1 = max(n1, n2);
	int max2 = max(n3, n4);
	int max3 = max(n5, n6);
	int max4 = max(max1, max2);
	return max(max3, max4);
}

void result_update(int target) {
	if (result < target) result = target;
}

int horizon_type(int nX, int nY) {
	if (nX + 3 >= M) return 0;

	return board[nY][nX] + board[nY][nX + 1] + board[nY][nX + 2] + board[nY][nX + 3];
}
int vertical_type(int nX, int nY) {
	if (nY + 3 >= N) return 0;

	return board[nY][nX] + board[nY + 1][nX] + board[nY + 2][nX] + board[nY + 3][nX];
}

int box_type(int nX, int nY) {
	if (nY + 1 >= N) return 0;
	if (nX + 1 >= M) return 0;

	return board[nY][nX] + board[nY][nX + 1] + board[nY + 1][nX] + board[nY + 1][nX + 1];
}

int three_horizon_type(int nX, int nY) {
	if (nX + 2 >= M) return 0;

	int max = board[nY][nX] + board[nY][nX + 1] + board[nY][nX + 2];
	
	if (nY == 0) {
		max += find_max(0, 0, 0, board[nY + 1][nX], board[nY + 1][nX + 1], board[nY + 1][nX + 2]);
	}
	else if (nY == N - 1) {
		max += find_max(0, 0, 0, board[nY - 1][nX], board[nY - 1][nX + 1], board[nY - 1][nX + 2]);
	}
	else {
		max += find_max(board[nY + 1][nX], board[nY + 1][nX + 1], board[nY + 1][nX + 2], board[nY - 1][nX], board[nY - 1][nX + 1], board[nY - 1][nX + 2]);
	}

	return max;
}

int three_vertical_type(int nX, int nY) {
	if (nY + 2 >= N) return 0;

	int max = board[nY][nX] + board[nY + 1][nX] + board[nY + 2][nX];

	if (nX == 0) {
		max += find_max(0, 0, 0, board[nY][nX + 1], board[nY + 1][nX + 1], board[nY + 2][nX + 1]);
	}
	else if (nX == M - 1) {
		max += find_max(0, 0, 0, board[nY][nX - 1], board[nY + 1][nX - 1], board[nY + 2][nX - 1]);
	}
	else {
		max += find_max(board[nY][nX + 1], board[nY + 1][nX + 1], board[nY + 2][nX + 1], board[nY][nX - 1], board[nY + 1][nX - 1], board[nY + 2][nX - 1]);
	}

	return max;
}

int two_horizon_type(int nX, int nY) {
	if (nX + 1 >= M) return 0;
	if (nY + 1 >= N) return 0;
	if (nY - 1 < 0) return 0;

	return board[nY][nX] + board[nY][nX + 1] + max(board[nY + 1][nX] + board[nY - 1][nX + 1], board[nY + 1][nX + 1] + board[nY - 1][nX]);
}

int two_vertical_type(int nX, int nY) {
	if (nY + 1 >= N) return 0;
	if (nX + 1 >= M) return 0;
	if (nX - 1 < 0) return 0;

	return board[nY][nX] + board[nY + 1][nX] + max(board[nY][nX + 1] + board[nY + 1][nX - 1], board[nY + 1][nX + 1] + board[nY][nX - 1]);
}

void game() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			result_update(horizon_type(x, y));
			result_update(vertical_type(x, y));
			result_update(box_type(x, y));
			result_update(three_horizon_type(x, y));
			result_update(three_vertical_type(x, y));
			result_update(two_horizon_type(x, y));
			result_update(two_vertical_type(x, y));
		}
	}
}

void solve() {
	input();
	game();

	cout << result;
}

int main() {
	solve();
	return 0;
}

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}
}