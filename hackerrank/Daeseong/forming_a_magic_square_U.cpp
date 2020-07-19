#include <iostream>
#include <algorithm>

using namespace std;

#define MID 1
#define MATRIX 3
#define NUM 10

int map[MATRIX][MATRIX];
int num[NUM];
// U ~ clock dir
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void input() {
	for (int y = 0; y < MATRIX; y++) {
		for (int x = 0; x < MATRIX; x++) {
			cin >> map[y][x];
		}
	}
}

bool is_ten(int a, int b) {
	if (a + b == 10) return true;
	else return false;
}

int solution() {
	int result = 0;
	if (map[MID][MID] != 5) {
		result += abs(map[MID][MID] - 5);
	}

	for (int y = 0; y < MATRIX; y++) {
		for (int x = 0; x < MATRIX; x++) {
			num[map[y][x]] += 1;
		}
	}

	for (int d = 0; d < 4; d++) {
		int a = map[MID + dy[d]][MID + dx[d]];
		int b = map[MID + dy[d + 4]][MID + dx[d + 4]];
		if (is_ten(a, b)) continue;

		if (num[a] != 1 && num[b] != 1) {
			if (num[NUM - a] == 0) {
				result += abs(map[MID + dy[d + 4]][MID + dx[d + 4]] - (NUM - a));
				map[MID + dy[d + 4]][MID + dx[d + 4]] = NUM - a;
			}
			else if (num[NUM - b] == 0) {
				result += abs(map[MID + dy[d]][MID + dx[d]] - (NUM - b));
				map[MID + dy[d]][MID + dx[d]] = NUM - b;
			}
		}
		else if (num[a] != 1) {
			num[a] = num[a] - 1;
			int temp = NUM - b;
			result += abs(a - temp);
			map[MID + dy[d]][MID + dx[d]] = temp;
			num[temp] = num[b] + 1;
		}
		else if (num[b] != 1) {
			num[b] = num[b] - 1;
			int temp = NUM - a;
			result += abs(b - temp);
			map[MID + dy[d + 4]][MID + dx[d + 4]] = temp;
			num[temp] = num[b] + 1;
		}
		else {
			if (num[NUM - a] == 0) {
				result += abs(map[MID + dy[d + 4]][MID + dx[d + 4]] - (NUM - a));
				map[MID + dy[d + 4]][MID + dx[d + 4]] = NUM - a;
			}
			else if (num[NUM - b] == 0) {
				result += abs(map[MID + dy[d]][MID + dx[d]] - (NUM - b));
				map[MID + dy[d]][MID + dx[d]] = NUM - b;
			}
		}
	}

	return result;
}

void show() {
	for (int y = 0; y < MATRIX; y++) {
		for (int x = 0; x < MATRIX; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}
}

void solve() {
	input();
	cout << solution() << endl;
	//show();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}