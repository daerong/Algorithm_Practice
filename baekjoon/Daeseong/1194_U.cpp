//Solution
//- DFS로 풀면 시간초과가 날 수 있음.
//- key보유 상황별로 맵을 만들어 가능한 경우수를 찾아야함.
//- DFS 순회시 다음의 룰을 따른다.
//- 1-1. 경로가 도출됐을 시, 그보다 이동수가 같거나 많은 경우, 이동을 중단한다.
//- 1-2. 맵을 벗어나거나 #을 만나면 중단한다.
//- 1-3. key가 없이 벽을 만나면 중단한다.
//- 1-4. 1을 만나면 결과를 업데이트하고 중단한다.
//- 2-1. 키를 만나면 키 상황을 업데이트한다.
//- 2-2. 현재 위치에 같은 키상황이 입력되어 있을 때는, 작은 경우에는 업데이트하고 큰 경우는 이동을 중단한다.
//- 2-3. 현재위치에 대해 { 이동수, 키상황 }을 저장한다.
//- 2-4. 키가 있는 경우, 벽에 대해서도 { 이동수, 키상황 }을 저장한다.

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

int N;		// 세로
int M;		// 가로
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