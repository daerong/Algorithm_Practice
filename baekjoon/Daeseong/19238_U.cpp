#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define N_MAX 21
#define DIST_MAX 2000000000

typedef struct MAN {
	int sx;
	int sy;
	int ex;
	int ey;
} MAN;

typedef struct DIST {
	int x;
	int y;
	int cnt;
} DIST;

bool compare(MAN a, MAN b) {
	if (a.ey == b.ey) return a.ex < b.ex;
	else return a.ey < b.ey;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int N;
int M;
int E;		// ¿¬·á
vector<vector<int>> map;
vector<vector<bool>> visited;
int tx;
int ty;
vector<MAN> man;

void init() {
	cin >> N >> M >> E;
	int temp;
	for (int y = 0; y < N; y++) {
		vector<int> int_line;
		vector<bool> bool_line;
		for (int x = 0; x < N; x++) {
			cin >> temp;
			int_line.push_back(temp);
			bool_line.push_back(false);
		}
		map.push_back(int_line);
		visited.push_back(bool_line);
	}
	cin >> ty >> tx;
	tx -= 1;
	ty -= 1;
	int sx, sy, ex, ey;
	for (int i = 0; i < M; i++) {
		cin >> sy >> sx >> ey >> ex;
		man.push_back({ sx - 1, sy - 1, ex - 1, ey - 1 });
	}
	sort(man.begin(), man.end(), compare);
}

int get_dist(int x, int y, vector<vector<bool>> cp) {
	queue<DIST> q;
	q.push({ tx, ty, 0 });
	while (!q.empty()) {
		DIST temp = q.front();
		q.pop();
		if (cp[temp.y][temp.x]) continue;
		if (temp.x == x && temp.y == y) return temp.cnt;
		cp[temp.y][temp.x] = true;
		if (map[temp.y][temp.x] == 1) continue;
		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.x + dx[dir];
			int ny = temp.y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			q.push({ nx, ny, temp.cnt + 1 });
		}
	}

	return -1;
}

int solution() {
	while (!man.empty()) {
		vector<MAN>::iterator target;
		int min_dist = DIST_MAX;
		//cout << tx + 1 << ", " << ty + 1 << endl;
		for (vector<MAN>::iterator iter = man.begin(); iter < man.end(); iter++) {
			int dist = get_dist(iter->sx, iter->sy, visited);
			if (dist == -1) return -1;
			if (dist < min_dist) {
				target = iter;
				min_dist = dist;
			}
		}

		if (E < min_dist) return -1;
		E -= min_dist;
		tx = target->sx;
		ty = target->sy;
		//cout << tx + 1 << ", " << ty + 1 << endl;

		min_dist = get_dist(target->ex, target->ey, visited);
		if (min_dist == -1) return -1;

		if (E < min_dist) return -1;
		else {
			E += min_dist;
			tx = target->ex;
			ty = target->ey;
			//cout << tx + 1 << ", " << ty + 1 << endl;
		}

		man.erase(target);
	}

	return E;
}

void solve() {
	init();
	cout << solution() << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}