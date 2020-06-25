#include <iostream>
#include <string>

using namespace std;

int result = 0;

int map[4][8];		// 1 = S±Ø, 0 = N±Ø
int K;
pair<int, int> num_dir[100];
int top_index[4] = { 0 };

void see_top() {
	for (int i = 0; i < 4; i++) {
		cout << top_index[i] << " ";
	}
	cout << endl;
}

void input() {
	string str[4];
	for (int i = 0; i < 4; i++) {
		cin >> str[i];
	}

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 8; i++) {
			if (str[j][i] == '0') map[j][i] = 0;
			else if (str[j][i] == '1') map[j][i] = 1;
		}
	}

	cin >> K;

	int f = 0;
	int s = 0;
	for (int i = 0; i < K; i++) {
		cin >> f >> s;
		num_dir[i].first = f - 1;
		num_dir[i].second = s;
	}
}

int find_left(int num, int top) {

	int left = top - 2;
	if (left < 0) left += 8;

	return map[num][left];
}
int find_right(int num, int top) {

	int right = top + 2;
	if (right >= 8) right -= 8;

	return map[num][right];
}

int inverse_turn(int dir) {
	if (dir < 0) return 1;
	else return -1;
}

void turn_end(int num, int dir) {
	top_index[num] -= dir;
	if (top_index[num] == -1) top_index[num] = 7;
	else if (top_index[num] == 8) top_index[num] = 0;
}

void move(int num, int dir, int lr) {
	// dir : 1 = ½Ã°è, -1 = ¹Ý½Ã°è
	// lr : -1 = Left, 1 = Right, 0 = ÃÊ±â

	int RO_left = -1;
	int NO_right = -1;
	int LO_right = -1;
	int NO_left = -1;

	if (num == 0) {
		RO_left = find_left(num + 1, top_index[num + 1]);
		NO_right = find_right(num, top_index[num]);
	}
	else if (num == 3) {
		LO_right = find_right(num - 1, top_index[num - 1]);
		NO_left = find_left(num, top_index[num]);
	}
	else {
		RO_left = find_left(num + 1, top_index[num + 1]);
		LO_right = find_right(num - 1, top_index[num - 1]);
		NO_left = find_left(num, top_index[num]);
		NO_right = find_right(num, top_index[num]);
	}

	if (NO_right != -1 && lr != -1) {
		if (RO_left != NO_right) move(num + 1, inverse_turn(dir), 1);
	}
	if (NO_left != -1 && lr != 1) {
		if (LO_right != NO_left) move(num - 1, inverse_turn(dir), -1);
	}


	turn_end(num, dir);
}

void result_update() {
	int mult = 1;
	int top = 0;
	for (int num = 0; num < 4; num++) {
		top = top_index[num];
		if (map[num][top] == 1) result += mult;

		mult *= 2;
	}
}

void see_map() {
	cout << endl << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void solve() {
	input();

	int nNum;
	int nDir;
	for (int cnt = 0; cnt < K; cnt++) {
		nNum = num_dir[cnt].first;
		nDir = num_dir[cnt].second;
		move(nNum, nDir, 0);
	}

	result_update();

	cout << result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}