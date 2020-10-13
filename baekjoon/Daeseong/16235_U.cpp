//Solution
//- ȿ���� ������ ���⶧���� �˰����� �� �����ؾ� �Ѵ�.
//- Fail 1: queue<TREE>�� vector<TREE>�� ����� ����� ����.
//	- TREE�� �þ�� ����, ������ �ݺ����� �þ.
//	- erase() ����� ���ϰ� ŭ.
//- Success : [row][col][year]�� ��� 3���� ���͸� ����ϸ� �ݺ��� ������� ������ �� ����.
//	- TREE�� ������ row * col * year�� ���� ����
//	- ���� ���ܳ��� TREE�� ���� 1�ӿ� ���� ���� ��ġ, ���� ���̸� ���� ���� ���� ����. -> �����ϴ�.
//- Ǯ�̰����� ������ ����.
//- 1. �Է°��� ���� ������ �����͸� �غ��Ѵ�.
//- 1.1. r�� c�� �ִ밪�� N���� ����.
//- 1.2. soil[r][c]�� ��� ���Ҹ� 5�� �ʱ�ȭ.
//- 1.3. A[r][c]�� S2D2�� �����ϴ� ��� �迭�� ����.
//- 1.4. tree[r][c][y]�� M���� ������ �����Ѵ�.
//- 2. K�� ���� each_year() �Լ��� �����Ѵ�.
//	- each_year()�� �� �Ű������� ���� �迭 trees�� ����迭 trees_temp�̴�.
//	- ���̰� ���� �������� ����� �Ծ� �����ϹǷ� ���� year�� ���� �ݺ������� ������ ������ �߰��ȴ�.
//	- �̸� �����ϱ� ���� trees_temp�� �߰��Ͽ� ���� �о���� �� ����Ѵ�.
//- 2.1. (r, c)�� ��� year�� ������������ ������ �ݺ��Ѵ�.
//- 2.1.1. trees[r][c][y]�� ���� 0�� ���, ���� �ݺ����� �����Ѵ�.
//- 2.1.2. ����ִ� ������ ���� ���Ѵ�. (��, live_cnt�� �ִ밪�� trees_temp[r][c][y]�̴�.)
//	- live_cnt = soil[r][c] / year
//- 2.1.3. ���� ������ ���� ���Ѵ�.
//	- dead_cnt = trees_temp[r][c][y] - live_cnt
//- 2.1.4. �Ÿ��� �Ҹ��Ѵ�.
//	- soil[r][c] -= live_cnt * year;
//- 2.1.5. ������ ���̸� ������Ų��. (live_cnt���� ����)
//	- trees[r][c][y] -> trees[r][c][y + 1]
//- 2.1.6. ������ �Ÿ����� �ٲ۴�. ��, ��ȯ�Ǵ� �Ÿ��� ���� ������ �����̸� �Ҽ��� ���ϴ� �����Ѵ�. (dead_cnt���� ����)
//	- trees[r][c][y] -= dead_cnt
//	- add_soil += (year / 2) * dead_cnt
//- 2.1.7. 2.1.6.���� ��ȯ�� ������ ������ŭ M�� �����Ѵ�.
//- 2.2. (r, c)�� ��� year�� ���� 5�� ����� year�� ������Ű�� ������ �����Ѵ�.
//- 2.2.1. �ش��ϴ� ������ ������ five_cnt�� ���Ѵ�.		(five_cnt�� ���ڰ� 5�� ����� ��� ������ ��)
//	- five_cnt += trees[r][c][y]
//- 2.2.2. (r, c)�ֺ� 8ĭ�� ���� ������ �����Ѵ�.
//- 2.2.2.1. ������ ����� ���� �ݺ����� �����Ѵ�.
//- 2.2.2.2. ������ ����� ������ trees[nr][nc][1]�� five_cnt�� ���Ѵ�. (nr, nc�� �ֺ� 8ĭ�� ������ ��ǥ)
//- 2.2.2.3. 2.2.2.2.���� ���� ������ ����ŭ M�� ������Ų��.
//- 2.3. (r, c)�� ��� ���ҿ� ���� A[r][c]�� ���� ���Ѵ�.



#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define N_MAX 10 + 1
#define YEAR_MAX 201

int dr[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dc[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int N;		// �� ũ��
int M;		// ���� ��
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