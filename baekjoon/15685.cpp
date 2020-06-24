#include <iostream>
#include <vector>

using namespace std;

typedef struct NODE {
	int x;
	int y;
} NODE;

#define N_MAX 20

int result = 0;
int N;				// °¹¼ö

vector<NODE> dr[N_MAX];		// x, y
int dir[N_MAX];
int gen[N_MAX];

int map[101][101] = { 0 };

// R, U, L, D
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void init_line(int index) {
	int x = dr[index].back().x;
	int y = dr[index].back().y;
	int d = dir[index];

	map[y][x] = 1;

	x += dx[d];
	y += dy[d];

	dr[index].push_back({ x, y });

	map[y][x] = 1;
}

void input() {
	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> dir[i] >> gen[i];
		dr[i].push_back({ x, y });
		init_line(i);
	}
}

void extend_node(int index, int baseX, int baseY, int targetX, int targetY) {
	int diffX = baseX - targetX;
	int diffY = baseY - targetY;
	int newX = baseX + diffY;
	int newY = baseY - diffX;

	dr[index].push_back({newX, newY});

	map[newY][newX] = 1;
}

void gen_update(int index) {
	int g = gen[index];
	NODE target;
	int nx, ny, vol;
	for (int i = 0; i < g; i++) {
		// gen ¹Ýº¹
		target = dr[index].back();
		nx = target.x;
		ny = target.y;
		vol = dr[index].size();

		for (int t = vol - 2; t >= 0; t--) {
			// ²¿¸®(vol - 1)¶û °¡±î¿î ¼øÀ¸·Î Ãß°¡
			extend_node(index, nx, ny, dr[index][t].x, dr[index][t].y);
		}
	}
}

//void draw_map() {
//	cout << endl;
//	for (int j = 0; j <= 100; j++) {
//		for (int i = 0; i <= 100; i++) {
//			cout << map[j][i];
//		}
//		cout << endl;
//	}
//}

int cnt_box() {
	int r = 0;
	for (int j = 1; j <= 100; j++) {
		for (int i = 1; i <= 100; i++) {
			if (map[j - 1][i - 1] + map[j - 1][i] + map[j][i - 1] + map[j][i] == 4) r += 1;
		}
	}

	return r;
}

void solve() {
	input();

	for (int i = 0; i < N; i++) {
		gen_update(i);
	}

	//draw_map();

	result = cnt_box();

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}