//Solution
//- dfs를 이용한다. map는 주변 지뢰갯수를 visited에는 방문여부를 각각 담는다.
//- step 1. 지뢰에는 -99를 넣고 visited를 true로 한다. 다음 지뢰 주변에 모두 1을 더한다.
//- step 2-1. 0인 칸은 visited 체크를 한 뒤, 주변 8칸의 0이상의 칸으로 이동한다.
//- step 2-2. 이동한 칸의 숫자가 1이상인 경우, visited에 체크만 하고 멈춘다.
//- step 2-3. 0인칸에서 퍼져나가 멈췄을 때, 그 한번을 하나의 시도로 한다.
//- step 3. 방문하지 않은 칸은 퍼져나갈 수 없는 칸이므로 각각이 하나의 시도를 의미한다.
//- step 4. step 2와 3의 시도의 합이 바로 결과이다.

#include <iostream>
#include <string>

using namespace std;

#define N_MAX 300
typedef struct LOCATE {
	int x;
	int y;
}LOCATE;

int map[N_MAX][N_MAX];
int visited[N_MAX][N_MAX];
int N;
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void input() {
	cin >> N;
	int nx, ny;
	string str;
	for (int y = 0; y < N; y++) {
		cin >> str;
		for (int x = 0; x < N; x++) {
			if (str[x] == '*') {
				map[y][x] = -99;
				visited[y][x] = true;
				for (int d = 0; d < 8; d++) {
					nx = x + dx[d];
					if (nx < 0 || nx >= N) continue;
					ny = y + dy[d];
					if (ny < 0 || ny >= N) continue;
					map[ny][nx] += 1;
				}
			}
		}
	}
}

void connect(int ix, int iy) {
	if (ix < 0 || ix >= N) return;
	if (iy < 0 || iy >= N) return;
	if (visited[iy][ix]) return;
	visited[iy][ix] = true;
	int nx, ny;
	if (map[iy][ix] == 0) {
		for (int d = 0; d < 8; d++) {
			nx = ix + dx[d];
			ny = iy + dy[d];
			connect(nx, ny);
		}
	}
}

int solution() {
	int answer = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x]) continue;
			if (map[y][x] == 0) {
				connect(x, y);
				answer++;
			}
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x]) continue;
			
			answer++;
		}
	}


	return answer;
}

void reset() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visited[y][x] = false;
			map[y][x] = 0;
		}
	}
}

void solve() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		input();
		cout << "#" << tc << " " << solution() << endl;
		reset();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}