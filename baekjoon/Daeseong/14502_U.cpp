#include <iostream>

using namespace std;

typedef struct LOCATE {
	int x;
	int y;
} LOCATE;

int result = 0;

int N;		// За
int M;		// ї­
int map[8][8] = { 0 };

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
}

void arr_cpy(int target[8][8], int original[8][8]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			target[y][x] = original[y][x];
		}
	}
}

bool virus(int target[8][8]) {
	bool is_change = false;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (target[y][x] == 2) {
				if (x != 0) {
					if (target[y][x - 1] == 0) { target[y][x - 1] = 2; is_change = true; }
				}
				if (x != M - 1) {
					if (target[y][x + 1] == 0) { target[y][x + 1] = 2; is_change = true; }
				}
				if (y != 0) {
					if (target[y - 1][x] == 0) { target[y - 1][x] = 2; is_change = true; }
				}
				if (y != N - 1) {
					if (target[y + 1][x] == 0) { target[y + 1][x] = 2; is_change = true; }
				}
			}
		}
	}

	return is_change;
}

int cnt_zero(int target[8][8]) {
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (target[y][x] == 0) cnt += 1;
		}
	}

	return cnt;
}

void result_update(int max) {
	if (result < max) result = max;
}

void make_wall(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp[8][8];
	arr_cpy(temp, map);

	temp[y1][x1] = 1;
	temp[y2][x2] = 1;
	temp[y3][x3] = 1;

	while(virus(temp)){}
	int max = cnt_zero(temp);
	result_update(max);

	
}

void solution() {
	for (int iy = 0; iy < N; iy++) {
		for (int ix = 0; ix < M; ix++) {
			if (map[iy][ix] != 0) continue;
			
			for (int jy = 0; jy < N; jy++) {
				for (int jx = 0; jx < M; jx++) {
					if (map[jy][jx] != 0) continue;
					if (iy * N + ix >= jy * N + jx) continue;

					for (int ky = 0; ky < N; ky++) {
						for (int kx = 0; kx < M; kx++) {
							if (map[ky][kx] != 0) continue;
							if (jy * N + jx >= ky * N + kx) continue;

							make_wall(ix, iy, jx, jy, kx, ky);
						}		
					}
				}
			}
		}
	}
}

void solve() {
	input();
	solution();
	cout << result;
}

int main() {
	solve();
	return 0;
}