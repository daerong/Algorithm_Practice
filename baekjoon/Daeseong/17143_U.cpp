//Solution
//- x�� �̵��ϸ� ����⸦ �����ø��Ƿ� �ִ� ��� ���� C�̴�.
//- index�� (1, 1)���� �����ϸ� ��� �̵� �� ������ ������.
//- Failed 1 : shark �迭�� ����ϴ� ������ ������ �߻���. ������ �����ѵ� ���ؿ����� �Ұ��� �ѵ�.
//	- vector<SHARK>�� ����Ͽ� �ذ�.
//= Ǯ�̰����� ������ ����.
//- 1. �� map[y][x]���� shark�� index�� vector<SHARK>���� �� ���� �ִ´�.
//	- �̵��Ÿ��� 0 ~ 2 * (N - 1)�� �ݺ��Ͽ� ��Ÿ����. ���� �� �̻��� ��� ��ⷯ �����Ͽ� �����Ѵ�.
//- 2. x�� �̵��ϸ� ������ �����Ѵ�.
//- 2.1. x��ġ�� ��� �� y�� ���� ���� �� ��´�.
//- 2.2. answer�� ����� ũ�⸦ ���Ѵ�.
//- 2.3. ��� �̵��� �����Ѵ�.
//- 2.3.1. �ڻ� ������ �ִ� ���, ������ �ݴ�������� ������Ʈ �Ѵ�.
//- 2.3.2. ���� �������� nx, ny�� ���� ������ �����Ѵ�.
//- 2.3.2.1. nx = ���.x + ���.direction_x * ���.distance;
//- 2.3.2.1.1. nx > 2 * (X - 1)�� ���, ������ �ι� �ٲ��. (���� ����)
//- 2.3.2.1.2. nx > X - 1�� ���, ������ �ѹ� �ٲ��. (�ݴ� ����)
//- 2.3.2.1.3. nx < -1 * (X - 1)�� ���, ������ �ι� �ٲ��. (���� ����)
//- 2.3.2.1.4. nx < 0�� ���, ������ �ѹ� �ٲ��. (�ݴ� ����)
//- 2.3.2.2. ny = ���.y + ���.direction_y * ���.distance;
//- 2.3.2.2.1. ny > 2 * (Y - 1)�� ���, ������ �ι� �ٲ��. (���� ����)
//- 2.3.2.2.2. ny > Y - 1�� ���, ������ �ѹ� �ٲ��. (�ݴ� ����)
//- 2.3.2.2.3. ny < -1 * (Y - 1)�� ���, ������ �ι� �ٲ��. (���� ����)
//- 2.3.2.2.4. ny < 0�� ���, ������ �ѹ� �ٲ��. (�ݴ� ����)
//- 2.3.3. map[ny][nx]�� �� �ִ� ���, �� ���� �� �����Ѵ�.
//- 2.3.4. 2.�� ���ư� ���� ���������� �ݺ��Ѵ�.
//- 3. answer�� ����Ѵ�.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAP_MAX 100 + 1

typedef struct SHARK {
	int x;
	int y;
	int dist;
	int dir;
	int size;
	bool die;
} SHARK;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int map[MAP_MAX][MAP_MAX];
vector<SHARK> vec;

int Y;		// ����
int X;		// ����
int M;

//void print_map(){
//	cout << "==============" << endl;
//	for (int y = 0; y < Y; y++) {
//		for (int x = 0; x < X; x++) {
//			cout << shark[map[y][x]].size << " ";
//		}
//		cout << endl;
//	}
//}

void move_shark() {
	for (int m = 1; m <= M; m++) map[vec[m].y][vec[m].x] = 0;
	for (int m = 1; m <= M; m++) {
		if (vec[m].die) continue;
		switch (vec[m].dir) {
		case 0:
			if (vec[m].y == 0) vec[m].dir = 2;
			break;
		case 1:
			if (vec[m].x == X - 1) vec[m].dir = 3;
			break;
		case 2:
			if (vec[m].y == Y - 1) vec[m].dir = 0;
			break;
		case 3:
			if (vec[m].x == 0) vec[m].dir = 1;
			break;
		}

		int nx = vec[m].x + dx[vec[m].dir] * vec[m].dist;
		int ny = vec[m].y + dy[vec[m].dir] * vec[m].dist;

		if (nx > 2 * (X - 1)) {
			nx = nx - 2 * (X - 1);
		}
		else if (nx > X - 1) {
			nx = 2 * (X - 1) - nx;
			vec[m].dir = 3;
		}

		if (nx < -1 * (X - 1)) {
			nx = 2 * (X - 1) + nx;
		}
		else if (nx < 0) {
			nx = abs(nx);
			vec[m].dir = 1;
		}

		if (ny > 2 * (Y - 1)) {
			ny = ny - 2 * (Y - 1);
		}
		else if (ny > Y - 1) {
			ny = 2 * (Y - 1) - ny;
			vec[m].dir = 0;
		}

		if (ny < -1 * (Y - 1)) {
			ny = 2 * (Y - 1) + ny;
		}
		else if (ny < 0) {
			ny = abs(ny);
			vec[m].dir = 2;
		}

		vec[m].x = nx;
		vec[m].y = ny;

		if (map[ny][nx] != 0) {
			if (vec[map[ny][nx]].size > vec[m].size) {
				vec[m].die = true;
			}
			else {
				vec[map[ny][nx]].die = true;
				map[ny][nx] = m;
			}
		}
		else {
			map[ny][nx] = m;
		}
	}
}

int solution() {
	int answer = 0;

	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
			if (map[y][x] != 0) {
				answer += vec[map[y][x]].size;
				vec[map[y][x]].die = true;
				break;
			}
		}

		move_shark();
		//print_map();
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vec.push_back({ 0, 0, 0, 0, 0, true });
	cin >> Y >> X >> M;
	for (int m = 1; m <= M; m++) {
		int x, y, s, d, z;
		cin >> y >> x >> s >> d >> z;
		map[y - 1][x - 1] = m;
		switch (d) {
		case 1:
			d = 0;
			s %= 2 * (Y - 1);
			break;
		case 2:
			d = 2;
			s %= 2 * (Y - 1);
			break;
		case 3:
			d = 1;
			s %= 2 * (X - 1);
			break;
		case 4:
			d = 3;
			s %= 2 * (X - 1);
			break;
		}

		vec.push_back({ x - 1 , y - 1, s, d, z, false });
	}

	cout << solution() << endl;

	return 0;
}