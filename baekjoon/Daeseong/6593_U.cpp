//Solution
//- BFS 사용, 최단거리 문제는 DFS로 풀면 늦음.

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAP_MAX 30
#define DEFAULT_RESULT 1000000000
typedef struct UDS {
	int x;
	int y;
	int z;
}UDS;

int L;		// z
int R;		// y
int C;		// x
UDS startD;
UDS endD;
char map[MAP_MAX][MAP_MAX][MAP_MAX];
int step[MAP_MAX][MAP_MAX][MAP_MAX];
int dx[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 1, -1, 0, 0, 0, 0 };

bool input() {
	cin >> L >> R >> C;
	if (L == 0) return false;

	for (int z = 0; z < L; z++) {
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				cin >> map[z][y][x];
				if (map[z][y][x] == 'S') startD = { x, y, z };
				else if(map[z][y][x] == 'E') endD = { x, y, z };
			}
		}
	}
	memset(step, 0, sizeof(step));
	return true;
}

void bfs() {
	queue<UDS> q;
	q.push(startD);
	UDS temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp.x == endD.x && temp.y == endD.y && temp.z == endD.z) {
			cout << "Escaped in " << step[temp.z][temp.y][temp.x] << " minute(s)." << endl;
			return;
		}
		int nx, ny, nz;
		for (int dir = 0; dir < 6; dir++) {
			nx = temp.x + dx[dir];
			if (nx < 0 || nx >= C) continue;
			ny = temp.y + dy[dir];
			if (ny < 0 || ny >= R) continue;
			nz = temp.z + dz[dir];
			if (nz < 0 || nz >= L) continue;
			if (step[nz][ny][nx] || map[nz][ny][nx] == '#') continue;
			step[nz][ny][nx] = step[temp.z][temp.y][temp.x] + 1;
			q.push({nx, ny, nz});
		}
	}
	cout << "Trapped!" << endl;
}

void solve() {
	while (input()) {
		bfs();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}