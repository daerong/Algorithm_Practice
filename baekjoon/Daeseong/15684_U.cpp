#include <iostream>
// code start
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 10 + 1
#define H_MAX 30 + 1

int answer = 7;

int N;		// 세로 실선
int H;		// 가로 점선
int M;		// 가로 실선 연결

bool map[H_MAX][N_MAX];
int add[N_MAX];

bool is_trick() {
	for (int x = 2; x < N - 1; x++) {
		int l = -1;
		int m = -1;
		int r = -1;
		for (int y = 1; y <= H; y++) {
			if (map[y][x - 1]) {
				if (l == -1) l = y;
				else if (l != -1 && m != -1 && m > l) {
					//cout << "1 : " << l << ", " << m << endl;
					return false;
				}
				else l = -1;
			}
			if (map[y][x]) {
				if (m == -1) m = y;
				else if (l != -1 && m != -1 && m < l) {
					//cout << "2 : " << l << ", " << m << endl;
					return false;
				}
				else if (r != -1 && m != -1 && m < r) {
					//cout << "3 : " << m << ", " << r << endl;
					return false;
				}
				else m = -1;

			}
			if (map[y][x + 1]) {
				if (r == -1) r = y;
				else if (r != -1 && m != -1 && m > r) {
					//cout << "4 : " << m << ", " << r << endl;
					return false;
				}
				else r = -1;
			}
		}
	}

	return true;
}

void dfs(int x, int cnt) {
	if (cnt > 3) return;
	if (x >= N) {
		//if (!map[6][2] || !map[5][4]) return;
		if (is_trick()) answer = min(answer, cnt);
		return;
	}
	if (add[x] % 2) {
		int do_cnt = 0;
		for (int y = 1; y <= H; y++) {
			if (map[y][x]) continue;
			bool is_can = true;
			if (x > 1) if (map[y][x - 1]) is_can = false;
			if (x < N - 1) if (map[y][x + 1]) is_can = false;
			if (!is_can) continue;
			do_cnt++;
			map[y][x] = true;
			add[x] += 1;
			//cout << x << ", " << y << ":" << cnt + 1 << endl;
			dfs(x + 1, cnt + 1);
			map[y][x] = false;
			add[x] -= 1;
		}
		if (do_cnt == 0) {
			answer = -1;
			return;
		}
	}
	else dfs(x + 1, cnt);
}

void show_map() {
	for (int y = 1; y <= H; y++) {
		for (int x = 1; x < N; x++) {
			if (map[y][x]) cout << "│─";
			else cout << "│ ";
		}
		cout << endl;
	}
}

int solution() {
	dfs(1, 0);
	//show_map();
	if (answer > 3) return -1;
	else return answer;
}

// code end
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;

	int a;		// 세로 위치, 왼쪽 1
	int b;		// 가로 위치, 맨 위 1
	for (int m = 1; m <= M; m++) {
		cin >> a >> b;
		map[a][b] = true;
		add[b] += 1;
	}

	cout << solution();

	return 0;
}