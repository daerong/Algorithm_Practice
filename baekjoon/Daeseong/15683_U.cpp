#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 8

int result = 1000000000;
int N;		// 세로
int M;		// 가로
int outer_map[MAX][MAX];

int cnt = 0;
typedef struct CAM {
	int type;
	int x;
	int y;
}CAM;

CAM cam[9];

// U, R, D, L
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> outer_map[y][x];
			if (outer_map[y][x] != 0 && outer_map[y][x] != 6) {
				cam[cnt].type = outer_map[y][x];
				cam[cnt].x = x;
				cam[cnt].y = y;
				cnt += 1;
			}
		}
	}
}

void area_check(int map[MAX][MAX], int nx, int ny, int dir) {
	int inner_x = nx + dx[dir];
	int inner_y = ny + dy[dir];

	if (inner_x < 0) return;
	if (inner_x >= M) return;
	if (inner_y < 0) return;
	if (inner_y >= N) return;

	while (true) {
		if (map[inner_y][inner_x] == 0) map[inner_y][inner_x] = 9;
		else if (map[inner_y][inner_x] == 6) break;

		inner_x = inner_x + dx[dir];
		inner_y = inner_y + dy[dir];

		if (inner_x < 0) break;
		if (inner_x >= M) break;
		if (inner_y < 0) break;
		if (inner_y >= N) break;
	}
}

int count_zero(int map[MAX][MAX]) {
	int zero = 0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < M; i++) {
			if (map[j][i] == 0) zero += 1;
		}
	}

	return zero;
}

void start(int num, int map[MAX][MAX]) {
	if (num == cnt) { 
		result = min(result, count_zero(map)); 
		return;
	}

	int type = cam[num].type;
	int x = cam[num].x;
	int y = cam[num].y;

	switch (type) {
	case 1:
		for (int dir = 0; dir < 4; dir++) {
			int inner_map[MAX][MAX];
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < M; i++) {
					inner_map[j][i] = map[j][i];
				}
			}
			area_check(inner_map, x, y, dir);
			start(num + 1, inner_map);
		}
		break;
	case 2:
		for (int dir = 0; dir < 2; dir++) {
			int inner_map[MAX][MAX];
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < M; i++) {
					inner_map[j][i] = map[j][i];
				}
			}
			area_check(inner_map, x, y, dir);
			area_check(inner_map, x, y, dir + 2);
			start(num + 1, inner_map);
		}
		break;
	case 3:
		for (int dir = 0; dir < 4; dir++) {
			int inner_map[MAX][MAX];
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < M; i++) {
					inner_map[j][i] = map[j][i];
				}
			}
			area_check(inner_map, x, y, dir);
			if (dir == 3) {
				area_check(inner_map, x, y, 0);
			}
			else {
				area_check(inner_map, x, y, dir + 1);
			}
			
			start(num + 1, inner_map);
		}
		break;
	case 4:
		for (int dir = 0; dir < 4; dir++) {
			int inner_map[MAX][MAX];
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < M; i++) {
					inner_map[j][i] = map[j][i];
				}
			}

			for (int n = 0; n < 4; n++) {
				if (dir == n) continue;
				area_check(inner_map, x, y, n);
			}
			
			start(num + 1, inner_map);
		}
		break;
	case 5:
		int inner_map[MAX][MAX];
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				inner_map[j][i] = map[j][i];
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			area_check(inner_map, x, y, dir);
		}
		
		start(num + 1, inner_map);
		break;
	}
}

void solve() {
	input();
	start(0, outer_map);

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}