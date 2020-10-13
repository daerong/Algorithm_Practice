//Solution
//- 효율성 기준이 높기때문에 알고리즘을 잘 설정해야 한다.
//- Fail 1: queue<TREE>와 vector<TREE>를 사용할 경우의 문제.
//	- TREE가 늘어남에 따라, 수행할 반복문이 늘어남.
//	- erase() 사용의 부하가 큼.
//- Success : [row][col][year]을 담는 3차원 벡터를 사용하면 반복문 실행수를 고정할 수 있음.
//	- TREE의 갯수와 row * col * year의 실행 차이
//	- 새로 생겨나는 TREE가 값이 1임에 따라 같은 위치, 같은 나이를 갖는 나무 수가 많음. -> 유리하다.
//- 풀이과정은 다음과 같다.
//- 1. 입력값을 통해 다음의 데이터를 준비한다.
//- 1.1. r과 c의 최대값을 N으로 설정.
//- 1.2. soil[r][c]의 모든 원소를 5로 초기화.
//- 1.3. A[r][c]에 S2D2가 제공하는 비료 배열을 저장.
//- 1.4. tree[r][c][y]에 M개의 나무를 저장한다.
//- 2. K년 동안 each_year() 함수를 실행한다.
//	- each_year()의 두 매개변수는 원본 배열 trees와 복사배열 trees_temp이다.
//	- 나이가 작은 나무부터 양분을 먹어 성장하므로 다음 year에 이전 반복문에서 성장한 나무가 추가된다.
//	- 이를 방지하기 위해 trees_temp를 추가하여 값을 읽어오는 데 사용한다.
//- 2.1. (r, c)의 모든 year의 오름차순으로 다음을 반복한다.
//- 2.1.1. trees[r][c][y]의 값이 0인 경우, 다음 반복문을 실행한다.
//- 2.1.2. 살아있는 나무의 수를 구한다. (단, live_cnt의 최대값은 trees_temp[r][c][y]이다.)
//	- live_cnt = soil[r][c] / year
//- 2.1.3. 죽은 나무의 수를 구한다.
//	- dead_cnt = trees_temp[r][c][y] - live_cnt
//- 2.1.4. 거름을 소모한다.
//	- soil[r][c] -= live_cnt * year;
//- 2.1.5. 나무의 나이를 증가시킨다. (live_cnt개의 나무)
//	- trees[r][c][y] -> trees[r][c][y + 1]
//- 2.1.6. 나무를 거름으로 바꾼다. 단, 변환되는 거름은 나무 나이의 절반이며 소수점 이하는 절사한다. (dead_cnt개의 나무)
//	- trees[r][c][y] -= dead_cnt
//	- add_soil += (year / 2) * dead_cnt
//- 2.1.7. 2.1.6.에서 변환된 나무의 갯수만큼 M을 차감한다.
//- 2.2. (r, c)의 모든 year에 대해 5의 배수로 year을 증가시키며 다음을 수행한다.
//- 2.2.1. 해당하는 나무의 갯수를 five_cnt에 더한다.		(five_cnt는 연자가 5의 배수인 모든 나무의 수)
//	- five_cnt += trees[r][c][y]
//- 2.2.2. (r, c)주변 8칸에 대해 다음을 수행한다.
//- 2.2.2.1. 범위를 벗어나면 다음 반복문을 수행한다.
//- 2.2.2.2. 범위를 벗어나지 않으면 trees[nr][nc][1]에 five_cnt를 더한다. (nr, nc는 주변 8칸의 임의의 좌표)
//- 2.2.2.3. 2.2.2.2.에서 더한 나무의 수만큼 M을 증가시킨다.
//- 2.3. (r, c)의 모든 원소에 대해 A[r][c]의 값을 더한다.



#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define N_MAX 10 + 1
#define YEAR_MAX 201

int dr[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dc[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int N;		// 맵 크기
int M;		// 나무 수
int K;		// term
int soil[N_MAX][N_MAX];
int A[N_MAX][N_MAX];

void each_year(vector<vector<vector<int>>>& trees, vector<vector<vector<int>>> trees_temp) {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int add_soil = 0;
			for (int y = 1; y < YEAR_MAX - 1; y++) {
				if (trees_temp[r][c][y] == 0) continue;

				int live_cnt = soil[r][c] / y;
				if (live_cnt > trees_temp[r][c][y]) live_cnt = trees_temp[r][c][y];
				int dead_cnt = trees_temp[r][c][y] - live_cnt;
				soil[r][c] -= live_cnt * y;
				trees[r][c][y] -= live_cnt;
				trees[r][c][y + 1] += live_cnt;

				trees[r][c][y] -= dead_cnt;
				add_soil += (y / 2) * dead_cnt;
				M -= dead_cnt;
			}

			soil[r][c] += add_soil;
		}
	}

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int five_cnt = 0;
			for (int y = 5; y < YEAR_MAX - 1; y += 5) {
				if (trees[r][c][y] != 0) {
					five_cnt += trees[r][c][y];
				}
			}

			if (five_cnt != 0) {
				for (int dir = 0; dir < 8; dir++) {
					int nr = r + dr[dir];
					int nc = c + dc[dir];
					if (nr <= 0 || nr > N || nc <= 0 || nc > N) continue;
					trees[nr][nc][1] += five_cnt;
					M += five_cnt;
				}
			}

			soil[r][c] += A[r][c];
		}
	}
}

int solution(int K, vector<vector<vector<int>>> trees) {
	for (int k = 1; k <= K; k++) {
		each_year(trees, trees);
	}

	return M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	vector<int> years;
	for (int y = 0; y < YEAR_MAX; y++) years.push_back(0);

	vector<vector<vector<int>>> trees;
	trees.push_back({});
	for (int r = 1; r <= N; r++) {
		vector<vector<int>> tree_row;
		tree_row.push_back(years);
		for (int c = 1; c <= N; c++) {
			cin >> A[r][c];
			soil[r][c] = 5;
			tree_row.push_back(years);
		}
		trees.push_back(tree_row);
	}

	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		trees[x][y][z] += 1;
	}

	cout << solution(K, trees);

	return 0;
}