#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define M_MAX 100

int N;
int map[M_MAX][M_MAX];
bool visited[M_MAX][M_MAX];
int min_map[M_MAX][M_MAX];

// R, D, L, U
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void input() {
	cin >> N;
	string str;
	for (int y = 0; y < N; y++) {
		cin >> str;
		for (int x = 0; x < N; x++) {
			map[y][x] = str[x] - '0';
		}
	}
}

void solution(int x, int y, int* cnt) {
	if (min_map[y][x] <= *cnt + map[y][x] || min_map[N - 1][N - 1] <= *cnt + map[y][x] || visited[y][x] || x < 0 || x >= N || y < 0 || y >= N) return;

	*cnt += map[y][x];

	min_map[y][x] = *cnt;
	visited[y][x] = true;

	for (int dir = 0; dir < 4; dir++) {
		solution(x + dx[dir], y + dy[dir], cnt);
	}

	*cnt -= map[y][x];
	visited[y][x] = false;
}

void print_min(int min_map[M_MAX][M_MAX]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << min_map[y][x];
		}

		cout << endl;
	}
}

void solve() {
	int T;
	cin >> T;
	int sum;
	for (int t = 1; t <= T; t++) {
		input();
		fill(&visited[0][0], &visited[N - 1][N], false);
		fill(&min_map[0][0], &min_map[N - 1][N], 1000000000);
		sum = 0;
		solution(0, 0, &sum);
		//print_min(min_map);
		cout << "#" << t << " " << min_map[N - 1][N - 1] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}