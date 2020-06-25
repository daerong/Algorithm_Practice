#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;		// 큐브 돌린 횟수

typedef struct TURN {
	char side;
	char dir;
}TURN;

// U, D, F, B, L, R
char map[6][9];

vector<TURN> turn[100];
int vol[100];

void input() {
	cin >> n;
	string str;
	TURN temp;
	for (int i = 0; i < n; i++) {
		cin >> vol[i];
		for (int j = 0; j < vol[i]; j++) {
			cin >> str;

			temp.side = str[0];
			temp.dir = str[1];
			turn[i].push_back(temp);
		}
	}

	for (int sd = 0; sd < 6; sd++) {
		// side
		for (int nm = 0; nm < 9; nm++) {
			// num
			switch (sd) {
			case 0:		// U
				map[sd][nm] = 'w';
				break;
			case 1:		// D
				map[sd][nm] = 'y';
				break;
			case 2:		// F
				map[sd][nm] = 'r';
				break;
			case 3:		// B
				map[sd][nm] = 'o';
				break;
			case 4:		// L
				map[sd][nm] = 'g';
				break;
			case 5:		// R
				map[sd][nm] = 'b';
				break;
			}
		}
	}
}

void all_change(char *target, char dir) {
	char temp[9];
	for (int i = 0; i < 9; i++) {
		temp[i] = target[i];
	}

	if (dir == '+') {
		target[0] = temp[6];
		target[1] = temp[3];
		target[2] = temp[0];
		target[3] = temp[7];
		target[4] = temp[4];
		target[5] = temp[1];
		target[6] = temp[8];
		target[7] = temp[5];
		target[8] = temp[2];
	}
	else {
		target[0] = temp[2];
		target[1] = temp[5];
		target[2] = temp[8];
		target[3] = temp[1];
		target[4] = temp[4];
		target[5] = temp[7];
		target[6] = temp[0];
		target[7] = temp[3];
		target[8] = temp[6];
	}
}

void after_change(char *a1, char *a2, char *a3, char *b1, char *b2, char *b3, char *c1, char *c2, char *c3, char *d1, char *d2, char *d3) {
	int z1 = *a1;
	int z2 = *a2;
	int z3 = *a3;
	*a1 = *b1;
	*a2 = *b2;
	*a3 = *b3;
	*b1 = *c1;
	*b2 = *c2;
	*b3 = *c3;
	*c1 = *d1;
	*c2 = *d2;
	*c3 = *d3;
	*d1 = z1;
	*d2 = z2;
	*d3 = z3;
}

void lets_turn(char side, char dir) {
	switch (side) {
	case 'U':		// U
		all_change(map[0], dir);
		if (dir == '+') {
			after_change(
				&map[2][0], &map[2][1], &map[2][2],
				&map[5][0], &map[5][1], &map[5][2],
				&map[3][0], &map[3][1], &map[3][2],
				&map[4][0], &map[4][1], &map[4][2]
			);
		}
		else {
			after_change(
				&map[2][0], &map[2][1], &map[2][2],
				&map[4][0], &map[4][1], &map[4][2],
				&map[3][0], &map[3][1], &map[3][2],
				&map[5][0], &map[5][1], &map[5][2]
			);
		}
		break;
	case 'D':		// D
		all_change(map[1], dir);
		if (dir == '+') {
			after_change(
				&map[2][6], &map[2][7], &map[2][8],
				&map[4][6], &map[4][7], &map[4][8],
				&map[3][6], &map[3][7], &map[3][8],
				&map[5][6], &map[5][7], &map[5][8]
			);
		}
		else {
			after_change(
				&map[2][6], &map[2][7], &map[2][8],
				&map[5][6], &map[5][7], &map[5][8],
				&map[3][6], &map[3][7], &map[3][8],
				&map[4][6], &map[4][7], &map[4][8]
			);
		}
		break;
	case 'F':		// F
		all_change(map[2], dir);
		if (dir == '+') {
			after_change(
				&map[0][6], &map[0][7], &map[0][8],
				&map[4][8], &map[4][5], &map[4][2],
				&map[1][2], &map[1][1], &map[1][0],
				&map[5][0], &map[5][3], &map[5][6]
			);
		}
		else {
			after_change(
				&map[0][6], &map[0][7], &map[0][8],
				&map[5][0], &map[5][3], &map[5][6],
				&map[1][2], &map[1][1], &map[1][0],
				&map[4][8], &map[4][5], &map[4][2]
			);
		}
		break;
	case 'B':		// B
		all_change(map[3], dir);
		if (dir == '+') {
			after_change(
				&map[0][2], &map[0][1], &map[0][0],
				&map[5][8], &map[5][5], &map[5][2],
				&map[1][6], &map[1][7], &map[1][8],
				&map[4][0], &map[4][3], &map[4][6]
			);
		}
		else {
			after_change(
				&map[0][2], &map[0][1], &map[0][0],
				&map[4][0], &map[4][3], &map[4][6],
				&map[1][6], &map[1][7], &map[1][8],
				&map[5][8], &map[5][5], &map[5][2]
			);
		}
		break;
	case 'L':		// L
		all_change(map[4], dir);
		if (dir == '+') {
			after_change(
				&map[0][0], &map[0][3], &map[0][6],
				&map[3][8], &map[3][5], &map[3][2],
				&map[1][0], &map[1][3], &map[1][6],
				&map[2][0], &map[2][3], &map[2][6]
			);
		}
		else {
			after_change(
				&map[0][0], &map[0][3], &map[0][6],
				&map[2][0], &map[2][3], &map[2][6],
				&map[1][0], &map[1][3], &map[1][6],
				&map[3][8], &map[3][5], &map[3][2]
			);
		}
		break;
	case 'R':		// R
		all_change(map[5], dir);
		if (dir == '+') {
			after_change(
				&map[0][8], &map[0][5], &map[0][2],
				&map[2][8], &map[2][5], &map[2][2],
				&map[1][8], &map[1][5], &map[1][2],
				&map[3][0], &map[3][3], &map[3][6]
			);
		}
		else {
			after_change(
				&map[0][8], &map[0][5], &map[0][2],
				&map[3][0], &map[3][3], &map[3][6],
				&map[1][8], &map[1][5], &map[1][2],
				&map[2][8], &map[2][5], &map[2][2]
			);
		}
		break;
	}
}

void input_check() {
	for (int i = 0; i < n; i++) {
		cout << vol[i] << endl;
		for (int j = 0; j < vol[i]; j++) {
			cout << turn[i][j].side << turn[i][j].dir << " ";
		}
		cout << endl;
	}
}

void see_top() {
	cout << map[0][0] << map[0][1] << map[0][2] << endl;
	cout << map[0][3] << map[0][4] << map[0][5] << endl;
	cout << map[0][6] << map[0][7] << map[0][8] << endl;
}


void start(int num) {
	int nVol = vol[num];
	for (int i = 0; i < nVol; i++) {
		char side = turn[num][i].side;
		char dir = turn[num][i].dir;
		lets_turn(side, dir);
	}
}

void map_cpy(char target[6][9], char source[6][9]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			target[i][j] = source[i][j];
		}
	}
}

void solve() {
	input();
	// input_check();
	char sub_map[6][9];
	map_cpy(sub_map, map);

	for (int i = 0; i < n; i++) {
		start(i);
		see_top();
		map_cpy(map, sub_map);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}