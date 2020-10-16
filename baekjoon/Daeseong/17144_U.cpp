//Solution
//- �־��� ���ǿ� �´� �Լ��� �ۼ��Ͽ� �ذ��� �� �ִ�.
//- �Ű������� ���� �迭�� �����ϱ� ���� vector�� ��Ҵ�.
//- Ǯ�̰����� ������ ����.
//- 1. �־��� �迭�� map[y][x]�� ��´�.
//- 2. ������ Tȸ �ݺ��Ѵ�.
//- 2.1. expand() �Լ��� �����迭 cp[y][x]�� Ȯ���Ͽ� �����迭 map[y][x]�� ������Ʈ�Ѵ�.
//- 2.1.1. ������ 4���� ���� �ش���� �� �ȿ� ��ġ�ϸ� ����û���� ��ġ�� �ƴ� ��� ������ �����Ѵ�.
//- 2.1.1.1. �ش� ��ġ�� cp[y][x] / 5�� ���ϰ� ���� ��ġ���� cp[y][x]�� ����.
//- 2.2. rotate() �Լ��� ����û���� ��ġ�� �������� �ð�, �ݽð� �������� ���� �̵���Ų��.
//- 2.2.1. ���� ���ʿ� ���� ������ �����Ѵ�.
//- 2.2.1.1. ����û���� �������� �̵��ϸ� ���� ��ġ�� ������ġ�� �����Ѵ�.
//- 2.2.1.2. ���̻� �̵��� �Ұ����� ���, �������� �̵��ϸ� �����Ѵ�.
//- 2.2.1.3. ���̻� �̵��� �Ұ����� ���, �������� �̵��ϸ� �����Ѵ�.
//- 2.2.1.4. ���̻� �̵��� �Ұ����� ���, �Ʒ������� �̵��ϸ� �����Ѵ�.
//- 2.2.1.5. ����û���� ��ġ�� ������ ���, ������ ���� �����Ѵ�.
//- 2.2.2. �Ʒ� ���ʿ� ���� ������ �����Ѵ�.
//- 2.2.2.1. ����û���� �������� �̵��ϸ� ���� ��ġ�� ������ġ�� �����Ѵ�.
//- 2.2.2.2. ���̻� �̵��� �Ұ����� ���, �Ʒ������� �̵��ϸ� �����Ѵ�.
//- 2.2.2.3. ���̻� �̵��� �Ұ����� ���, �������� �̵��ϸ� �����Ѵ�.
//- 2.2.2.4. ���̻� �̵��� �Ұ����� ���, �������� �̵��ϸ� �����Ѵ�.
//- 2.2.2.5. ����û���� ��ġ�� ������ ���, ������ ���� �����Ѵ�.
//- 3. �ݺ� �� map�� ���� ������ ������ ���Ͽ� ����Ѵ�.

#include <iostream>
#include <vector>

using namespace std;

#define M_MAX 50

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int R;		// ����
int C;		// ����
int T;
vector<vector<int>> map;
int up_y = -1;
int dn_y = -1;

void expand(vector<vector<int>> cp) {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			int expand_var = cp[y][x] / 5;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
				else if (nx == 0) {
					if (ny == up_y || ny == dn_y) continue;
				}

				map[ny][nx] += expand_var;
				map[y][x] -= expand_var;
			}
		}
	}
}

void rotate(vector<vector<int>> cp) {
	int end_x = 0;
	int end_y = up_y;
	int x = 0;
	int y = up_y;
	int dir = 1;
	do {
		if (x == C - 1 && y == end_y) dir = 0;
		else if (x == C - 1 && y == 0) dir = 3;
		else if (x == 0 && y == 0) dir = 2;

		int next_x = x + dx[dir];
		int next_y = y + dy[dir];
		map[next_y][next_x] = cp[y][x];
		x = next_x;
		y = next_y;
	} while (end_x != x || end_y != y);
	map[y][x] = 0;

	end_x = 0;
	end_y = dn_y;
	x = 0;
	y = dn_y;
	dir = 1;
	do {
		if (x == C - 1 && y == end_y) dir = 2;
		else if (x == C - 1 && y == R - 1) dir = 3;
		else if (x == 0 && y == R - 1) dir = 0;

		int next_x = x + dx[dir];
		int next_y = y + dy[dir];
		map[next_y][next_x] = cp[y][x];
		x = next_x;
		y = next_y;
	} while (end_x != x || end_y != y);
	map[y][x] = 0;
}

//void print_map() {
//	cout << "====================" << endl;
//	for (int y = 0; y < R; y++) {
//		for (int x = 0; x < C; x++) {
//			cout << map[y][x] << " ";
//		}
//		cout << endl;
//	}
//}

int solution() {
	for (int t = 1; t <= T; t++) {
		expand(map);
		rotate(map);
		//print_map();
	}

	int answer = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			answer += map[y][x];
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;
	int temp;
	for (int y = 0; y < R; y++) {
		vector<int> line;
		for (int x = 0; x < C; x++) {
			cin >> temp;

			if (temp == -1) {
				if (up_y == -1) up_y = y;
				else dn_y = y;

				line.push_back(0);
			}
			else line.push_back(temp);
		}
		map.push_back(line);
	}

	cout << solution() << endl;

	return 0;
}