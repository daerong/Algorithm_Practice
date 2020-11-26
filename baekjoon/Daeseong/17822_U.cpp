//Solution
//- 원형으로 주어진 2차원배열을 BFS로 순회하여 시뮬레이션 하는 문제
//- 회전이라는 개념을 머릿속으로 그려내기가 어려워 실수했다.
//- 1. 12시를 기준으로 시계방향으로 index가 증가한다.
//- 2. arrow 배열에 현재 12시 위치의 index를 담는다. (시작의 12시 index는 0이며 시계방향으로 증가)
//- 3. 반시계 방향 회전시 index가 증가하며, 시계방향 회전시 index가 감소한다.
//- 풀이는 다음과 같다.
//1. 입력을 받는다.
//1.1. N, M, T
//1.2. map에는 숫자를 저장한다.
//1.3. turn에는 회전 정보를 저장한다.
//1.4. arrow에는 원판 별로 12시 위치 index를 담는다. (초기값 0)
//2. 회전을 수행한다. rotate()
//2.1. 증감을 수행하되, M보다 크거나 같은 경우와 0보다 작은 경우에 주의한다.
//3. 조건에 따라 숫자를 변경시킨다.
//3.1. DFS를 순회하며 같은 값을 찾아 0으로 변경한다.
//3.2. 0으로 변경한 값이 없는 경우, 다음을 수행한다.
//3.2.1. 0이 아닌 숫자의 합(sum)과 그 갯수(cnt)를 구한다.
//3.2.2. 평균 E를 구한다. E = sum / cnt
//3.2.3. map에서 0이 아닌 숫자를 찾아 다음을 수행한다.
//3.2.3.1. E보다 큰 경우, 1을 뺀다.
//3.2.3.2. E보다 작은 경우, 1을 더한다.
//4. 모든 회전에 대해 2.부터 반복한다.
//5. 남은 숫자의 합을 구해서 출력한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;		// 원판
int M;		// 숫자
vector<vector<int>> map;
vector<vector<int>> turn;		// 배수, dir, 칸수
vector<int> arrow;				// 12시 : 0, 시계방향 증가

int dl[] = { -1, 1 };

void input() {
	int T;
	cin >> N >> M >> T;

	int temp;
	for (int n = 0; n < N; n++) {
		vector<int> line;
		for (int m = 0; m < M; m++) {
			cin >> temp;
			line.push_back(temp);
		}
		map.push_back(line);
		arrow.push_back(0);
	}
	for (int t = 0; t < T; t++) {
		vector<int> line;
		for (int i = 0; i < 3; i++) {
			cin >> temp;
			if (temp == 0) temp = -1;
			line.push_back(temp);
		}
		turn.push_back(line);
	}
}

void rotate(int t) {
	int x = turn[t][0];
	int d = turn[t][1];
	int k = turn[t][2];

	for (int r = x - 1; r < N; r += x) {
		arrow[r] += d * k;
		while (arrow[r] < 0) arrow[r] += M;
		arrow[r] %= M;
	}
}

void update(vector<vector<int>> cp) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> vec;

	bool is_change = false;

	for (int y = 0; y < N; y++) {
		for (int i = 0; i < M; i++) {
			int x = (i + arrow[y]) % M;
			if (cp[y][x] == 0) continue;
			int target = cp[y][x];
			vec.push_back({ y, x });
			cp[y][x] = 0;
			q.push({ y, i });
			while (!q.empty()) {
				int ny = q.front().first;
				int ni = q.front().second;
				q.pop();
				for (int d = 0; d < 2; d++) {
					int dy = ny + dl[d];
					if (dy < 0 || dy >= N) continue;
					int dx = (ni + arrow[dy]) % M;
					if (cp[dy][dx] == 0) continue;
					if (cp[dy][dx] != target) continue;
					vec.push_back({ dy, dx });
					cp[dy][dx] = 0;
					q.push({ dy, ni });
				}
				for (int d = 0; d < 2; d++) {
					int di = ni + dl[d];
					if (di < 0) di += M;
					int dx = (di + arrow[ny]) % M;
					if (cp[ny][dx] == 0) continue;
					if (cp[ny][dx] != target) continue;
					vec.push_back({ ny, dx });
					cp[ny][dx] = 0;
					q.push({ ny, di });
				}
			}

			if (vec.size() > 1) {
				is_change = true;
				for (vector<pair<int, int>>::iterator it = vec.begin(); it != vec.end(); it++) {
					map[(*it).first][(*it).second] = 0;
				}
			}

			vec.clear();
		}
	}

	if (!is_change) {
		double sum = 0;
		int cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] != 0) {
					sum += map[y][x];
					cnt++;
				}
			}
		}
		double E = sum / cnt;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] != 0) {
					if (map[y][x] > E) map[y][x] -= 1;
					else if (map[y][x] < E) map[y][x] += 1;
				}
			}
		}
	}
}

void solution() {
	input();
	for (int t = 0; t < turn.size(); t++) {
		rotate(t);
		update(map);
	}

	int sum = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			sum += map[y][x];
		}
	}

	cout << sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}