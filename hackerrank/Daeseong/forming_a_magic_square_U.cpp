// start : pm 5:33
// end : 

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MID 1

int result;

bool check[3][3];
int num[3][3];

void input() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> num[y][x];
		}
	}
}

void ten_check(int diff_x, int diff_y) {
	
	if (num[MID - diff_y][MID - diff_x] + num[MID + diff_y][MID + diff_x] == 10) {
		check[MID - diff_y][MID - diff_x] = true;
		check[MID + diff_y][MID + diff_x] = true;
	}
}

void true_check() {
	ten_check(1, 1);
	ten_check(0, 1);
	ten_check(1, 0);
	ten_check(1, -1);

	for (int x = 0; x < 3; x++) {
		if (num[0][x] + num[1][x] + num[2][x] == 15) {
			check[0][x] = true;
			check[1][x] = true;
			check[2][x] = true;
		}
	}
	for (int y = 0; y < 3; y++) {
		if (num[y][0] + num[y][1] + num[y][2] == 15) {
			check[y][0] = true;
			check[y][1] = true;
			check[y][2] = true;
		}
	}
}

int find_diff(int target_x, int target_y) {
	int diff = 0;

	int horizon = 0;
	int vertical = 0;
	int diagonal = 0;

	for (int x = 0; x < 3; x++) {
		horizon += num[target_y][x];
	}
	for (int y = 0; y < 3; y++) {
		vertical += num[y][target_x];
	}

	if (target_x == 1 || target_y == 1) {
		if (horizon == vertical) return 15 - horizon;
	}
	else {
		switch (target_x + target_y) {
		case 0:
		case 4:
			diagonal += num[0][0] + num[1][1] + num[2][2];
			break;
		case 2:
			diagonal += num[2][0] + num[1][1] + num[0][2];
			break;
		}

		//cout << "h" << horizon << endl;
		//cout << "v" << vertical << endl;
		//cout << "d" << diagonal << endl;

		if (horizon == vertical) return 15 - horizon;
		if (horizon == diagonal) return 15 - diagonal;
		if (diagonal == vertical) return 15 - diagonal;
	}

	return diff;
}

void solution() {
	if (num[MID][MID] != 5) {
		result += abs(num[MID][MID] - 5);
		num[MID][MID] = 5;
	}
	check[MID][MID] = true;

	true_check();

	int temp;
	bool lotate = true;

	while (lotate) {
		lotate = false;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				if (check[y][x]) continue;
				//cout << y << ", " << x << ", X" << endl;

				temp = find_diff(x, y);
				if (temp) {
					// 0ÀÌ ¾Æ´Ò ¶§, 
					lotate = true;

					num[y][x] += temp;
					check[y][x] = true;

					//cout << y << ", " << x << ", " << temp << endl;

					result += abs(temp);
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}