//Solution
//- 아래 문항중 참, 거짓은 최종상태, 최종상태가 아님을  각각 의미한다.
//- 1. 4개 이하의 돌만 있는 경우 거짓 (3x3 게임판이므로 4개 이하의 돌로는 게임을 끝낼 수 없다)
//- 2. X갯수 = O갯수 또는 X갯수 = O갯수 + 1이 성립하지 않는 경우 거짓 (번갈아가며 게임, X가 선)
//- 3. X가 마지막에 두었을 때는 O가, O일때는 X가 연결되어 있으면 거짓 (연결된 순간 종료되어야 함)
//- 4-1. X가 5개, O가 4개인 경우는 항상 참.
//- 4-2. X턴에 X가, O턴에 O가 연결되어 있지 않으면 거짓 (연결되지 않으면 종료되지 않음)

#include <iostream>
#include <string>
using namespace std;

#define MAP_MAX 3

char map[MAP_MAX][MAP_MAX];
int nO;
int nX;

bool input() {
	nO = 0;
	nX = 0;
	for (int y = 0; y < MAP_MAX; y++) {
		for (int x = 0; x < MAP_MAX; x++) {
			cin >> map[y][x];
			switch (map[y][x]) {
			case 'X':
				nX++;
				break;
			case 'O':
				nO++;
				break;
			case '.':
				break;
			default:
				return false;
			}
		}
	}
	return true;
}

bool connection_check(char target) {
	for (int y = 0; y < MAP_MAX; y++) {
		if (map[y][1] != target) continue;
		if (map[y][0] == target && map[y][2] == target) return true;
	}
	for (int x = 0; x < MAP_MAX; x++) {
		if (map[1][x] != target) continue;
		if (map[0][x] == target && map[2][x] == target) return true;
	}
	
	if (map[1][1] == target) {
		if (map[0][0] == target && map[2][2] == target) return true;
		if (map[2][0] == target && map[0][2] == target) return true;
	}

	return false;
}

void solution() {
	if (nX + nO < 5) {
		cout << "invalid" << endl;
		return;
	}
	if (nX == nO) {
		if (connection_check('X')) {
			cout << "invalid" << endl;
			return;
		}

		if (connection_check('O')) {
			cout << "valid" << endl;
			return;
		}
		else {
			cout << "invalid" << endl;
			return;
		}
	}
	else if (nX == nO + 1) {
		if (connection_check('O')) {
			cout << "invalid" << endl;
			return;
		}

		if (connection_check('X')) {
			cout << "valid" << endl;
			return;
		}
		else {
			if (nX + nO == 9) {
				cout << "valid" << endl;
				return;
			}
			else {
				cout << "invalid" << endl;
				return;
			}
		}
	}
	else {
		cout << "invalid" << endl;
		return;
	}
}

void solve() {
	while (input()) {
		solution();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}