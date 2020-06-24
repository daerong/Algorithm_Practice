#include <iostream>

using namespace std;

int result = 0;

int N;
int L;
int map[100][100];

void input() {
	cin >> N;
	cin >> L;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			cin >> map[j][i];
		}
	}
}

void vertical(int row) {
	int last_height = map[0][row];

	int max_line = 1;
	for (int col = 1; col < N; col++) {

		if (map[col][row] == last_height) {
			// 높이 같음
			max_line += 1;
		}
		else if (map[col][row] == last_height + 1) {
			// 더 높은 블럭
			if (max_line < L) return;
			max_line = 1;
		}
		else if (map[col][row] == last_height - 1) {
			// 더 낮은 블럭
			if (col + L - 1 > N) return;
			for (int i = 1; i < L; i++) {

				if (map[col + i][row] != map[col][row]) return;
			}
			col += L - 1;
			max_line = 0;
		}
		else return;

		last_height = map[col][row];
	}

	result += 1;
}

void horizon(int col) {
	int last_height = map[col][0];

	int max_line = 1;
	for (int row = 1; row < N; row++) {

		if (map[col][row] == last_height) {
			// 높이 같음
			max_line += 1;
		}
		else if (map[col][row] == last_height + 1) {
			// 더 높은 블럭
			if (max_line < L) return;
			max_line = 1;
		}
		else if(map[col][row] == last_height - 1){
			// 더 낮은 블럭
			if (row + L - 1 > N) return;
			for (int i = 1; i < L; i++) {

				if (map[col][row + i] != map[col][row]) return;
			}
			row += L - 1;
			max_line = 0;
		}
		else return;

		last_height = map[col][row];
	}

	result += 1;
}

void solve() {
	input();

	for (int x = 0; x < N; x++) {
		vertical(x);
		horizon(x);
	}


	cout << result;
}


int main() {
	solve();
	return 0;
}