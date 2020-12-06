#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct LOCATE {
	int x;
	int y;
};
typedef struct MAN {
	int id;
	bool served;
	LOCATE start;
	LOCATE end;
} PASSANGER;
typedef struct DIST {
	int dist;
	MAN man;
} DIST;

bool operator <(DIST a, DIST b) {
	if (a.dist == b.dist) {
		if (a.man.start.y == b.man.start.y) return a.man.start.x < b.man.start.x;
		else return a.man.start.y < b.man.start.y;
	}
	else return a.dist < b.dist;
}

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int N;
int M;
int K;		// ¿¬·á
vector<vector<int>> map;
vector<MAN> man;
LOCATE taxi;

void init() {
	cin >> N >> M >> K;
	int temp;
	for (int y = 0; y < N; y++) {
		vector<int> line;
		for (int x = 0; x < N; x++) {
			cin >> temp;
			line.push_back(temp);
		}
		map.push_back(line);
	}
	cin >> taxi.y >> taxi.x;
	MAN passanger;
	for (int m = 1; m <= M; m++) {
		passanger.id = m;
		passanger.served = false;
		cin >> passanger.start.y >> passanger.start.x >> passanger.end.y >> passanger.end.x;
		man.push_back(passanger);
	}
}

void get_dist(int x, int y, LOCATE target, int cnt, int* l) {
	if (target.x == x && target.y == y) {
		*l = min(*l, cnt);
		return;
	}
	if (cnt >= *l) return;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (map[ny][nx] == 1) continue;

		get_dist(nx, ny, target, cnt + 1, l);
	}
}

LOCATE move() {
	LOCATE target;
	priority_queue<DIST> dist;
	for (vector<MAN>::iterator iter = man.begin(); iter < man.end();) {
		if (!(*iter).served) {
			int l = 1000000000;
			get_dist(taxi.x, taxi.y, (*iter).start, 0, &l);
			dist.push({ l, *iter });
		}
		iter++;
	}
	if (dist.size() == 0) {

	}
	else if (dist.top().dist == 1000000000) {
		target.x = -1;
		target.y = -1;
	}
	else if (dist.top().dist > K) {
		target.x = -1;
		target.y = -1;
	}
	else {
		K -= dist.top().dist;
		taxi.x = dist.top().man.start.x;
		taxi.y = dist.top().man.start.y;
		target = dist.top().man.end;
	}

	return target;
}

void solve() {
	init();
	while (man.size() > 0) {
		LOCATE target = move();
		if (target.x == -1) {
			cout << -1 << endl;
			break;
		}

		int l = 1000000000;
		get_dist(taxi.x, taxi.y, target, 0, &l);

		if (l == 1000000000) {
			cout << -1 << endl;
			break;
		}
		else if (l > K) {
			cout << -1 << endl;
			break;
		}
		else {
			K += l;
			taxi.x = target.x;
			taxi.y = target.y;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}