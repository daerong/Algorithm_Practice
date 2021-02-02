//Solution
//- � �� �ϴ� �������� �������� ���ӿ� ����, �Ķ� ������ ���� �߰��Ǿ���. Blue ������ ���� ����ó���� ����
//- DFS�� ����ؼ� Ǯ���ߴ�.
//- �̷��� ������ ������ ����.
//- 1. ������ �ϴ� ���� �������θ� �̵��� �� �ִ�. ���� �ΰ��� ������ ��� ���� ������ ������ �̵��Ѵ�.
//- 2. ������ ��ġ�� ���, �̵��Ÿ��� ū ������ ��ĭ ������ �ǵ�����.
//- 3. � ��쿡���� �Ķ� ������ ������ ���� �����Ѵ�.
//- 4. ���� Ƚ���� 10�� �ѱ�� ��� �����Ѵ�.
//- 5. ���������� Ż�� ���� ���, 1�� ����Ѵ�.
//- 6. �� ���� ��� 0�� ����Ѵ�.
//- Failed 1 : ���� ������� Ǯ�������� �߰��� ������ �߸� ����ѵ��ϴ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. map[][] : ���� ���¸� ������ �迭, 'R'�� 'B'�� '.'���� ġȯ�ߴ�.
//- 1.2. RX, RY : �ʱ� Red ������ ��ġ�� ������ ����
//- 1.3. BX, BY : �ʱ� Blue ������ ��ġ�� ������ ����
//- 1.4. answer : ����� ������ ���� default�� 0
//- 2. move() �Լ��� ����� �������� �� �ִ� ����� ���� DFS�� ã�´�.
//- 2.1. ù ������ RX, RY, BX, BY, 1�� ����Ѵ�.
//- 2.2. 4���⿡ ���� ���� ������ �����Ѵ�.
//- 2.2.1. Blue ���� �̵���Ų��.
//- 2.2.2. Blue ���� 'O'�� ���� ���, ���� �ݺ��� �����Ѵ�.
//- 2.2.3. Blue ���� '#'�� ���� ���, �ٷ� ���� ��ġ�� nBx, nBy�� �Ѵ�.
//- 2.2.4. Red ���� �̵���Ų��.
//- 2.2.5. Red ���� 'O'�� ���� ���, answer�� 1�� �����ϰ� 3.���� �̵��Ѵ�.
//- 2.2.6. Red ���� '#'�� ���� ���, �ٷ� ���� ��ġ�� nRx, nRy�� �Ѵ�.
//- 2.3. Red ���� Blue ���� ��ġ�� ���� ���, ������ �����Ѵ�.
//- 2.3.1. Red ���� �̵��Ÿ��� Blue ���� �̵��Ÿ��� ���Ѵ�.
//- 2.3.2. Red Dist�� ū ���, Red ���� �ٷ� ���� ��ġ�� nRx, nRy�� �Ѵ�.
//- 2.3.3. Blue Dist�� ū ���, Blue ���� �ٷ� ���� ��ġ�� nBx, nBy�� �Ѵ�.
//- 2.4. move() �Լ��� nRx, nRy, nBx, nBy, turn + 1�� �־� 2.2.�� ���ư���.
//- 3. answer�� ����Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 10

int X, Y;
char map[N_MAX][N_MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int RX, RY;
int BX, BY;
int answer;

void init() {
	cin >> Y >> X;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'R') {
				RX = x;
				RY = y;
				map[y][x] = '.';
			}
			else if (map[y][x] == 'B') {
				BX = x;
				BY = y;
				map[y][x] = '.';
			}
		}
	}
}

void move(int Rx, int Ry, int Bx, int By, int turn) {
	if (answer == 1) return;
	if (turn > 10) return;

	for (int dir = 0; dir < 4; dir++) {
		int nBx = Bx;
		int nBy = By;
		bool is_fall = false;
		while (map[nBy][nBx] != '#') {
			nBx += dx[dir];
			nBy += dy[dir];
			if (map[nBy][nBx] == 'O') {
				is_fall = true;
				break;
			}
		}
		if (is_fall) continue;
		nBx -= dx[dir];
		nBy -= dy[dir];

		int nRx = Rx;
		int nRy = Ry;
		is_fall = false;
		while (map[nRy][nRx] != '#') {
			nRx += dx[dir];
			nRy += dy[dir];
			if (map[nRy][nRx] == 'O') {
				is_fall = true;
				break;
			}
		}
		if (is_fall) {
			answer = 1;
			return;
		}
		nRx -= dx[dir];
		nRy -= dy[dir];

		if (nRx == nBx && nRy == nBy) {
			int Rdiff = abs(nRx + nRy - Rx - Ry);
			int Bdiff = abs(nBx + nBy - Bx - By);
			if (Rdiff > Bdiff) {
				nRx -= dx[dir];
				nRy -= dy[dir];
			}
			else {
				nBx -= dx[dir];
				nBy -= dy[dir];
			}
		}

		move(nRx, nRy, nBx, nBy, turn + 1);
	}
}

void solution() {
	init();
	move(RX, RY, BX, BY, 1);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}