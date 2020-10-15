//Solution
//- �α� ���̰� L <= diff <= R�� ��� ���� �����ϴ� ������.���� ������ ���� ���� ����� ���ؾ� �Ѵ�.
//- union�� parent chain ����� �߻��� ���, ���� ��Ұ� �ٸ� parent ��Ҹ� ������ �ǹǷ� �� �ѹ� �� Ȯ������.
//- Ǯ�� ������ ������ ����.
//- 1. �־��� �α� �迭�� map[y][x]�� �����Ѵ�.
//- 2. ����� �������� �ʱ�ȭ�Ѵ�.
//- 2.1.parent[y * N + x]�� y * N + x�� �ʱ�ȭ
//- 2.2.sum[y * N + x]�� map[y][x]�� �ʱ�ȭ
//- 2.3.cnt[y * N + x]�� 1�� �ʱ�ȭ
//- 2.4.visited[y][x]�� false�� �ʱ�ȭ
//- 3. opening(x, y) �Լ����� ������ ����.
//- ��� x, y�� ���� �ּ� �ѹ��� �����Ѵ�. (�̹� ����� ���󿡼��� �ٸ� ����� ������ �߻��� �� ����)
//- 3.1.�湮 ���θ� üũ�Ѵ�.
//- 3.1.1.�湮�� ���, �������� �ʴ´�.
//- 3.1.2.�湮���� ���� ���, �Ʒ��� �����Ѵ�.
//- 3.2.�̿��� 4������ ���� ���� ������ �����Ѵ�.
//- 3.2.1.���� ����� �̿��� ������ ���� diff�� ���Ѵ�.
//- 3.2.2.L < diff < R�� ���, �� ���� index�� ���� parent�� union�� �����Ѵ�.
//- 3.2.2.1.���� parent�� cnt�� ���Ѵ�.
//- 3.2.2.2.���� parent�� sum�� ���Ѵ�.
//- 3.2.2.3.���� parent�� ��ġ��Ų��.
//- 3.3.�̿��� 4������ ���� ���� 3�� �ݺ��Ѵ�.


#include <iostream>
#include <vector>

	using namespace std;

#define N_MAX 50

int N;		// �� MAX
int L;		// �α����� L�̻�
int R;		// �α����� R����

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int map[N_MAX][N_MAX];
int parent[N_MAX * N_MAX];
int sum[N_MAX * N_MAX];
int cnt[N_MAX * N_MAX];
bool visited[N_MAX][N_MAX];

int opening_cnt;

int get_parent(int target) {
	if (parent[target] == target) return target;

	return parent[target] = get_parent(parent[target]);
}

void opening(int x, int y) {
	if (opening_cnt == N * N) return;
	if (visited[y][x]) return;
	visited[y][x] = true;
	opening_cnt++;

	int id = y * N + x;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		int nid = ny * N + nx;

		int diff = abs(map[y][x] - map[ny][nx]);
		if (diff >= L && diff <= R) {
			int Parent = get_parent(id);
			int nParent = get_parent(nid);
			if (Parent > nParent) {
				cnt[nParent] += cnt[Parent];
				cnt[Parent] = 0;
				sum[nParent] += sum[Parent];
				sum[Parent] = 0;
				parent[Parent] = nParent;
			}
			else if (Parent < nParent) {
				cnt[Parent] += cnt[nParent];
				cnt[nParent] = 0;
				sum[Parent] += sum[nParent];
				sum[nParent] = 0;
				parent[nParent] = Parent;
			}
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		opening(nx, ny);
	}
}

bool moving() {
	bool check = false;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int Parent = get_parent(y * N + x);
			if (cnt[Parent] != 1) check = true;
			map[y][x] = sum[Parent] / cnt[Parent];
		}
	}

	return check;
}

//void print_map() {
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cout << map[y][x] << " ";
//		}
//
//		cout << endl;
//	}
//}
//
//void print_parent() {
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cout << get_parent(y * N + x) << " ";
//		}
//
//		cout << endl;
//	}
//}

void solution() {
	int moveing_cnt = -1;
	do {
		//print_map();
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				int locate = y * N + x;
				parent[locate] = locate;
				sum[locate] = map[y][x];
				cnt[locate] = 1;
				visited[y][x] = false;
			}
		}
		opening_cnt = 0;
		opening(0, 0);
		//print_parent();
		moveing_cnt++;
	} while (moving());

	cout << moveing_cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	solution();

	return 0;
}