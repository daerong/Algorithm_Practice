#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 50

typedef struct LOCATE {
	int n;
	int m;
} LOCATE;

typedef struct TURN {
	int x;		// x의 배수 원판
	int d;		// dir = 시계 -1, 반시계 1
	int k;		// k칸
} TURN;

vector<vector<int>> map;
int top[MAX];
vector<TURN> turn;
int N;		// 원판 수
int M;		// 숫자 수
int T;		// 회전 수

void bfs(vector<vector<int>> cp) {
	queue<LOCATE> q;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (cp[n][m] == 0) continue;
			q.push({ n, m });
			while (!q.empty()) {

			}
		}
	}
}

void rotate() {
	for (int t = 0; t < T; t++) {
		for (int i = turn[t].x; i < N; i += turn[t].x) {
			top[i] += turn[t].d * turn[t].k;
			while (top[i] < 0) top[i] += M;
			top[i] %= M;
		}

		bfs(map);
	}
}

void solve() {
	cin >> N >> M >> T;

	int temp;
	for (int n = 0; n < N; n++) {
		vector<int> line;
		for (int m = 0; m < M; m++) {
			cin >> temp;
			line.push_back(temp);
		}
		map.push_back(line);
	}

	int x, d, k;
	for (int t = 0; t < T; t++) {
		cin >> x >> d >> k;
		turn.push_back({ x, d, k });
	}

	rotate();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}