//Solution
//- ��ٸ�Ÿ�� ���������� ���������� ������ ������� ã�ư��� ����� ����
//- map ��ü�� 2�� �ϳ����̹Ƿ� 2�� �������� path�� ���󰣴ٸ� ������ ���� Ǯ �� �ִ�.
//- �̷��� ������ ������ ����.
//- 1. 2�� �������� ������ �����Ѵ�.
//- 2. �¿쿡 1�� ���ٸ� y - 1�� �̵��Ѵ�.
//- 3. �¿쿡 1�� �ִٸ� 0 �������� �� �̵��Ѵ�.
//- 4. y = 0�� �Ǵ� ���������� x�� ����Ѵ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1.map[][] : map ������� 100 x 100���� ����.�־��� ���� �Է��Ѵ�.
//- 1.2.goal : 2�� x��ġ. (y�� MAP_SIZE - 1)
//- 2. path(x, y, dir)�� �����Ѵ�.
//- 2.1.dir == 0�� ���,
//-2.1.1.����(map[y][x - 1])�� ���� 1�� ���, path(x - 1, y, dir = -1)
//- 2.1.2.����(map[y][x + 1])�� ���� 1�� ���, path(x + 1, y, dir = 1)
//- 2.1.3.�¿� �Ѵ� 0�� ���, path(x, y - 1, dir = 0)
//- 2.2.dir == -1�� ���,
//-2.2.1.����(map[y][x - 1])�� ���� 1�� ���, path(x - 1, y, dir = -1)
//- 2.2.2.�� ���� ���, path(x, y - 1, dir = 0)
//- 2.3.dir == 1�� ���,
//-2.3.1.����(map[y][x + 1])�� ���� 1�� ���, path(x + 1, y, dir = 1)
//- 2.3.2.�� ���� ���, path(x, y - 1, dir = 0)
//- 3. y == 0�� ��, x�� ���� ����Ѵ�.

#include <iostream>

using namespace std;

#define MAP_SIZE 100

int map[MAP_SIZE + 1][MAP_SIZE + 1];
int goal_x;
int answer;

void init() {
	for (int y = 0; y < MAP_SIZE; y++) {
		for (int x = 0; x < MAP_SIZE; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) goal_x = x;
		}
	}
}

void path(int x, int y, int dir) {
	if (y == 0) {
		answer = x;
		return;
	}

	switch (dir) {
	case -1:
		if (x == 0 || map[y][x - 1] == 0) {
			path(x, y - 1, 0);
		}
		else {
			path(x - 1, y, -1);
		}
		break;
	case 1:
		if (x == MAP_SIZE - 1 || map[y][x + 1] == 0) {
			path(x, y - 1, 0);
		}
		else {
			path(x + 1, y, 1);
		}
		break;
	case 0:
		if (x > 0 && map[y][x - 1] == 1) {
			path(x - 1, y, -1);
		}
		else if (x < MAP_SIZE - 1 && map[y][x + 1] == 1) {
			path(x + 1, y, 1);
		}
		else {
			path(x, y - 1, 0);
		}
		break;
	}
}

void solution() {
	int turn;
	for (int i = 0; i < 10; i++) {
		cin >> turn;
		init();
		path(goal_x, MAP_SIZE - 1, 0);
		cout << "#" << turn << " " << answer << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}