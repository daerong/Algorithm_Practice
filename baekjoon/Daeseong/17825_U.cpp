#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int turn[10];		// 턴 정보
int stone[4];		// 말 위치
int base[] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35 };

void init() {
	for (int t = 0; t < 10; t++) turn[t] = 0;
	for (int t = 0; t < 10; t++) cin >> turn[t];
	for (int i = 0; i < 4; i++) stone[i] = 0;
}

int move(int target, int cnt) {
	switch (stone[target]) {
	case 5:
		if (cnt <= 3) stone[target] = 20 + cnt;
		else stone[target] = 25 + cnt;
		break;
	case 21:
	case 22:
	case 23:
		stone[target] += cnt;
		if (stone[target] > 23) stone[target] = 28 + stone[target] - 23;
		break;
	case 10:
		if (cnt <= 2) stone[target] = 23 + cnt;
		else stone[target] = 26 + cnt;
		break;
	case 24:
	case 25:
		stone[target] += cnt;
		if (stone[target] > 25) stone[target] = 28 + stone[target] - 25;
		break;
	case 15:
		stone[target] = 25 + cnt;
		break;
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
		stone[target] += cnt;
		if (stone[target] > 31) stone[target] = -1;
		break;
	default:
		stone[target] += cnt;
		if (stone[target] > 20) stone[target] = -1;
	}

	return stone[target];
}

void dfs(int t, int sum) {
	//cout << t << ", " << sum << endl;
	if (t == 10) {
		//answer = max(answer, sum);
		return;
	}

	int before, next;
	for (int i = 0; i < 4; i++) {
		if (stone[i] == -1) continue;
		before = stone[i];
		next = move(i, turn[t]);
		if (next == -1) {
			dfs(t + 1, sum);
			stone[i] = before;
		}
		else {
			bool is_same = false;
			for (int j = 0; j < 4; j++) {
				if (i == j) continue;
				if (stone[i] == stone[j]) is_same = true;
			}
			if (!is_same) {
				dfs(t + 1, sum + base[next]);
				stone[i] = before;
			}
		}
	}

	answer = max(answer, sum);
}

void solution() {
	init();
	dfs(0, 0);

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}