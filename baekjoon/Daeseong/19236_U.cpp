#include <iostream>
#include <vector>

using namespace std;

typedef struct FISH {
	int x;
	int y;
	int dir;
	bool is_dead;
} FISH;

int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int N = 4;
int answer = 0;

vector<FISH> fishes;

vector<vector<int>> input() {
	for (int i = 0; i <= 16; i++) fishes.push_back({ -1, -1, -1, false });

	vector<vector<int>> map;
	for (int y = 0; y < N; y++) {
		vector<int> line;
		for (int x = 0; x < N; x++) {
			int index, dir;
			cin >> index >> dir;
			fishes[index].x = x;
			fishes[index].y = y;
			fishes[index].dir = dir - 1;
			line.push_back(index);
		}

		map.push_back(line);
	}

	return map;
}

string print_dir(int dir) {
	switch (dir) {
	case 0: return "¡è";
	case 1: return "¢Ø";
	case 2: return "¡ç";
	case 3: return "¢×";
	case 4: return "¡é";
	case 5: return "¢Ù";
	case 6: return "¡æ";
	case 7: return "¢Ö";
	}
}
void print_map(int shark_x, int shark_y, vector<vector<int>> cp_map) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (x == shark_x && y == shark_y) cout << "S ";
			else if (fishes[cp_map[y][x]].is_dead) cout << "X ";
			else if (cp_map[y][x] >= 10) cout << cp_map[y][x];
			else cout << "0" << cp_map[y][x];
			cout << print_dir(fishes[cp_map[y][x]].dir) << " ";
		}
		cout << endl;
	}
}

void fish_move(int shark_x, int shark_y, vector<vector<int>>& cp_map) {
	for (int i = 1; i < fishes.size(); i++) {
		if (fishes[i].is_dead) continue;
		FISH* origin = &fishes[i];
		FISH* target = nullptr;

		for (int angle = 0; angle < 8; angle++) {
			int temp_dir = origin->dir + angle;
			if (temp_dir >= 8) temp_dir -= 8;

			int nx = origin->x + dx[temp_dir];
			int ny = origin->y + dy[temp_dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (nx == shark_x && ny == shark_y) continue;

			int target_id = cp_map[ny][nx];
			target = &fishes[target_id];
			break;
		}

		if (target != nullptr) {
			int temp = cp_map[target->y][target->x];
			cp_map[target->y][target->x] = cp_map[origin->y][origin->x];
			cp_map[origin->y][origin->x] = temp;
			temp = target->x;
			target->x = origin->x;
			origin->x = temp;
			temp = target->y;
			target->y = origin->y;
			origin->y = temp;
		}
	}
}

void shark_move(int x, int y, int cnt, vector<vector<int>> map) {
	if (fishes[map[y][x]].is_dead) return;
	fishes[map[y][x]].is_dead = true;

	int summation = cnt + map[y][x];
	int dir = fishes[map[y][x]].dir;

	vector<vector<int>> cp_map;
	cp_map.assign(map.begin(), map.end());

	fish_move(x, y, cp_map);

	cout << print_dir(dir) << ", " << summation << endl;
	print_map(x, y, cp_map);

	for (int len = 1; len <= 3; len++) {
		int nx = x + dx[dir] * len;
		int ny = y + dy[dir] * len;
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		shark_move(nx, ny, summation, cp_map);
	}

	if (answer < summation) answer = summation;
	fishes[map[y][x]].is_dead = false;
}

void solution() {
	vector<vector<int>> map = input();
	shark_move(0, 0, 0, map);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}