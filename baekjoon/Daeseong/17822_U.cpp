//Solution
//- �������� �־��� 2�����迭�� BFS�� ��ȸ�Ͽ� �ùķ��̼� �ϴ� ����
//- ȸ���̶�� ������ �Ӹ������� �׷����Ⱑ ����� �Ǽ��ߴ�.
//- 1. 12�ø� �������� �ð�������� index�� �����Ѵ�.
//- 2. arrow �迭�� ���� 12�� ��ġ�� index�� ��´�. (������ 12�� index�� 0�̸� �ð�������� ����)
//- 3. �ݽð� ���� ȸ���� index�� �����ϸ�, �ð���� ȸ���� index�� �����Ѵ�.
//- Ǯ�̴� ������ ����.
//1. �Է��� �޴´�.
//1.1. N, M, T
//1.2. map���� ���ڸ� �����Ѵ�.
//1.3. turn���� ȸ�� ������ �����Ѵ�.
//1.4. arrow���� ���� ���� 12�� ��ġ index�� ��´�. (�ʱⰪ 0)
//2. ȸ���� �����Ѵ�. rotate()
//2.1. ������ �����ϵ�, M���� ũ�ų� ���� ���� 0���� ���� ��쿡 �����Ѵ�.
//3. ���ǿ� ���� ���ڸ� �����Ų��.
//3.1. DFS�� ��ȸ�ϸ� ���� ���� ã�� 0���� �����Ѵ�.
//3.2. 0���� ������ ���� ���� ���, ������ �����Ѵ�.
//3.2.1. 0�� �ƴ� ������ ��(sum)�� �� ����(cnt)�� ���Ѵ�.
//3.2.2. ��� E�� ���Ѵ�. E = sum / cnt
//3.2.3. map���� 0�� �ƴ� ���ڸ� ã�� ������ �����Ѵ�.
//3.2.3.1. E���� ū ���, 1�� ����.
//3.2.3.2. E���� ���� ���, 1�� ���Ѵ�.
//4. ��� ȸ���� ���� 2.���� �ݺ��Ѵ�.
//5. ���� ������ ���� ���ؼ� ����Ѵ�.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;		// ����
int M;		// ����
vector<vector<int>> map;
vector<vector<int>> turn;		// ���, dir, ĭ��
vector<int> arrow;				// 12�� : 0, �ð���� ����

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