#include <iostream>

using namespace std;

int result = 0;
int N;
int M;
int rx;
int ry;
int dir;
// ºÏ, µ¿, ³², ¼­
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int map[50][50];

void input() {
	cin >> N >> M;
	cin >> ry >> rx >> dir;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
}

bool turn() {
	bool is_turn = false;
	int x;
	int y;

	for (int i = 0; i < 4; i++) {
		dir = dir - 1;
		if (dir == -1) dir = 3;

		x = rx + dx[dir];
		y = ry + dy[dir];
		if (map[y][x] == 0) {
			is_turn = true;
			break;
		}
	}
	return is_turn;
}

bool move() {

	if (map[ry][rx] == 1) return false;
	else if (map[ry][rx] == 0) {
		map[ry][rx] = 2;
		result += 1;
	}

	bool can_move = turn();

	if (can_move) {
		rx = rx + dx[dir];
		ry = ry + dy[dir];
	}
	else {
		rx = rx - dx[dir];
		ry = ry - dy[dir];
	}

	return true;
}

void solution() {
	bool is_working = true;
	while (is_working) {
		is_working = move();
	}
	map[ry][rx] = 9;
}

void see() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
}

void solve() {
	input();
	solution();
	//see();
	cout << result;
}


int main() {
	solve();
	return 0;
}