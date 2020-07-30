//Solution
//- �Ʒ� ������ ��, ������ ��������, �������°� �ƴ���  ���� �ǹ��Ѵ�.
//- 1. 4�� ������ ���� �ִ� ��� ���� (3x3 �������̹Ƿ� 4�� ������ ���δ� ������ ���� �� ����)
//- 2. X���� = O���� �Ǵ� X���� = O���� + 1�� �������� �ʴ� ��� ���� (�����ư��� ����, X�� ��)
//- 3. X�� �������� �ξ��� ���� O��, O�϶��� X�� ����Ǿ� ������ ���� (����� ���� ����Ǿ�� ��)
//- 4-1. X�� 5��, O�� 4���� ���� �׻� ��.
//- 4-2. X�Ͽ� X��, O�Ͽ� O�� ����Ǿ� ���� ������ ���� (������� ������ ������� ����)

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