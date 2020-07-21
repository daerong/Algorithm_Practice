//Solution
//- dfs�� �̿��Ѵ�. map�� �ֺ� ���ڰ����� visited���� �湮���θ� ���� ��´�.
//- step 1. ���ڿ��� -99�� �ְ� visited�� true�� �Ѵ�. ���� ���� �ֺ��� ��� 1�� ���Ѵ�.
//- step 2-1. 0�� ĭ�� visited üũ�� �� ��, �ֺ� 8ĭ�� 0�̻��� ĭ���� �̵��Ѵ�.
//- step 2-2. �̵��� ĭ�� ���ڰ� 1�̻��� ���, visited�� üũ�� �ϰ� �����.
//- step 2-3. 0��ĭ���� �������� ������ ��, �� �ѹ��� �ϳ��� �õ��� �Ѵ�.
//- step 3. �湮���� ���� ĭ�� �������� �� ���� ĭ�̹Ƿ� ������ �ϳ��� �õ��� �ǹ��Ѵ�.
//- step 4. step 2�� 3�� �õ��� ���� �ٷ� ����̴�.

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