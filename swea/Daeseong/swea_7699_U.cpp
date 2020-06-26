// start : am 1:53
// end : am 3:23	(server connection error)

// 가능한 경로로 탐색진행
// 1. 왔던경로로 돌아가지 않음.
// 2. 막힌경우 진행하지 않음.
// 3. 예외처리 - 맵크기가 1, 1인경우


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAP_LIMIT 20

int	T;
int R;			// y
int C;			// x
char map[MAP_LIMIT][MAP_LIMIT];
int result;

void move(bool *checked, int x, int y, int *cnt, int dir) {
	if (checked[map[y][x] - 'A']) {
		// already visite
		result = max(result, *cnt);
		return;
	}

	checked[map[y][x] - 'A'] = true;
	*cnt += 1;
	
	switch (dir) {
	case 0:
		if (x != C - 1) move(checked, x + 1, y, cnt, 0);
		if (y != 0) move(checked, x, y - 1, cnt, 3);
		if (y != R - 1) move(checked, x, y + 1, cnt, 1);
		break;
	case 1:
		if (x != 0) move(checked, x - 1, y, cnt, 2);
		if (x != C - 1) move(checked, x + 1, y, cnt, 0);
		if (y != R - 1) move(checked, x, y + 1, cnt, 1);
		break;
	case 2:
		if (x != 0) move(checked, x - 1, y, cnt, 2);
		if (y != 0) move(checked, x, y - 1, cnt, 3);
		if (y != R - 1) move(checked, x, y + 1, cnt, 1);
		break;
	case 3:
		if (x != 0) move(checked, x - 1, y, cnt, 2);
		if (x != C - 1) move(checked, x + 1, y, cnt, 0);
		if (y != 0) move(checked, x, y - 1, cnt, 3);
		break;
	}

	checked[map[y][x] - 'A'] = false;
	*cnt -= 1;

}

void input() {
	bool checked[26] = { false, };
	int cnt = 0;

	string str;
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		cin >> str;
		for (int x = 0; x < C; x++) {
			map[y][x] = str[x];
		}
	}
	if (R + C == 2) result = 1;
	else move(checked, 0, 0, &cnt, 0);
}

void solution() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		result = 0;
		input();
		cout << "#" << t + 1 << " " << result << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}