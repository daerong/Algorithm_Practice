#include <iostream>
#include <queue>

#define N_MAX 1000

using namespace std;

int N;
long long map[N_MAX][N_MAX];
bool visited[N_MAX][N_MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

long long result_i;
long long result_c;

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			visited[y][x] = false;
		}
	}
	result_i = -1;
	result_c = -1;
}
void make_graph(int x, int y, long long *index, long long *cnt) {
	visited[y][x] = true;
	*cnt += 1;

	int nx, ny;
	for (int dir = 0; dir < 4; dir++) {
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (visited[ny][nx]) continue;
		if (map[y][x] == map[ny][nx] + 1) {
			*index = map[ny][nx];
			make_graph(nx, ny, index, cnt);
		}
		else if (map[y][x] == map[ny][nx] - 1) {
			make_graph(nx, ny, index, cnt);
		}
	}
}

void connect() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x]) continue;
			long long temp_i = map[y][x];
			long long temp_c = 0;
			make_graph(x, y, &temp_i, &temp_c);
			if (result_c < temp_c) {
				result_i = temp_i;
				result_c = temp_c;
			}
			else if (result_c == temp_c) {
				result_i = min(result_i, temp_i);
			}
		}
	}
}
void solution() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		input();
		connect();
		cout << "#" << tc << " " << result_i << " " << result_c << endl;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}