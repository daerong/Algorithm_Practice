//Solution
//- DFS�� Ǯ�� �ð��ʰ��� �� �� ����.
//- key���� ��Ȳ���� ���� ����� ������ ������ ã�ƾ���.
//- DFS ��ȸ�� ������ ���� ������.
//- 1-1. ��ΰ� ������� ��, �׺��� �̵����� ���ų� ���� ���, �̵��� �ߴ��Ѵ�.
//- 1-2. ���� ����ų� #�� ������ �ߴ��Ѵ�.
//- 1-3. key�� ���� ���� ������ �ߴ��Ѵ�.
//- 1-4. 1�� ������ ����� ������Ʈ�ϰ� �ߴ��Ѵ�.
//- 2-1. Ű�� ������ Ű ��Ȳ�� ������Ʈ�Ѵ�.
//- 2-2. ���� ��ġ�� ���� Ű��Ȳ�� �ԷµǾ� ���� ����, ���� ��쿡�� ������Ʈ�ϰ� ū ���� �̵��� �ߴ��Ѵ�.
//- 2-3. ������ġ�� ���� { �̵���, Ű��Ȳ }�� �����Ѵ�.
//- 2-4. Ű�� �ִ� ���, ���� ���ؼ��� { �̵���, Ű��Ȳ }�� �����Ѵ�.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define MAP_MAX 50
#define KEY_MAX 6
typedef struct UDS {
	int cnt;
	string key;
} UDS;

int N;		// ����
int M;		// ����
char map[MAP_MAX][MAP_MAX];
vector<UDS> check[MAP_MAX][MAP_MAX];
int xx;
int yy;
int result;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void input() {
	cin >> N >> M;
	string str;
	for (int y = 0; y < N; y++) {
		cin >> str;
		for (int x = 0; x < M; x++) {
			map[y][x] = str[x];
			if (map[y][x] == '0') {
				xx = x;
				yy = y;
				map[y][x] = '.';
			}
		}
	}
}

void move(int x, int y, int cnt, string str) {
	if (cnt >= result) return;
	if (y < 0 || y >= N) return;
	if (x < 0 || x >= M) return;
	int locate;
	switch (map[y][x]) {
	case '#': 
		return;
	case '1':
		result = cnt;
		return;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		locate = map[y][x] - 'A';
		if (str[locate] == '0') return;
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
		locate = map[y][x] - 'a';
		str[locate] = map[y][x];
		break;
	}

	bool is_change = false;
	for (int i = 0; i < check[y][x].size(); i++) {
		if (check[y][x][i].key == str) {
			if (check[y][x][i].cnt <= cnt) return;
			check[y][x][i].cnt = cnt;
			is_change = true;
			break;
		}
	}

	if (!is_change) check[y][x].push_back({cnt, str});

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		move(nx, ny, cnt + 1, str);
	}
}

void solve() {
	input();
	result = 100000000;
	move(xx, yy, 0, "000000");
	if (result == 100000000) cout << -1;
	else cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}