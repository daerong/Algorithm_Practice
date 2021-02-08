#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define N_MAX 51

typedef struct LOCATE {
	int x;
	int y;
} LOCATE;

typedef struct NODE {
	LOCATE locate;
	int time;
} NODE;

int X, Y;
int map[N_MAX][N_MAX];
bool visited[N_MAX][N_MAX];
bool visited2[N_MAX][N_MAX];
queue<NODE> wet;
LOCATE start;
LOCATE finish;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1 ,0 };
int answer = 2000000000;

void init() {
	cin >> Y >> X;
	char temp;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> temp;
			switch (temp) {
			case '.':
				map[y][x] = 0;
				break;
			case 'X':
				map[y][x] = -1;
				break;
			case '*':
				map[y][x] = 0;
				wet.push({ {x, y}, 1 });
				break;
			case 'D':
				map[y][x] = -1;
				finish.x = x;
				finish.y = y;
				break;
			case 'S':
				map[y][x] = 0;
				start.x = x;
				start.y = y;
				break;
			}
		}
	}
}

void bfs() {
	NODE temp;
	while (!wet.empty()) {
		temp = wet.front();
		wet.pop();

		if (visited[temp.locate.y][temp.locate.x]) continue;
		visited[temp.locate.y][temp.locate.x] = true;
		map[temp.locate.y][temp.locate.x] = temp.time;
		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.locate.x + dx[dir];
			int ny = temp.locate.y + dy[dir];
			if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
			if (map[ny][nx] == -1) continue;
			wet.push({ {nx, ny}, temp.time + 1 });
		}
	}
}

void dfs(int x, int y, int step) {
	if (x == finish.x && y == finish.y) {
		answer = min(answer, step);
		return;
	}
	if (map[y][x] == -1) return;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
		if (map[ny][nx] != -1 && map[ny][nx] <= step) continue;
		if (visited2[ny][nx]) continue;
		visited2[ny][nx] = true;
		dfs(nx, ny, step + 1);
		visited2[ny][nx] = false;
	}
}

void solution() {
	init();
	bfs();
	dfs(start.x, start.y, 2);
	if (answer == 2000000000) cout << "KAKTUS" << endl;
	else cout << answer - 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}