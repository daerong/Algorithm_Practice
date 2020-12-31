//Solution
//- (0, 0)���� (N, M)���� ���� ���ڷθ� �̵��ϴ� ����� ���� ���ϴ� ����
//- DFS, DP
//- �⺻���� �̷��� ������ ����.
//- 1. (X, Y)�� �̵������� ��� ����� ���� (X, Y)�� ���������� �̵�����̴�.
//- 2. ���� (N, M)�� �������� ����Լ��� �����ϸ� ��� �н��� ���� �̵���� ���� �� �� �ִ�.
//- 3. �� �������� ������ ���� �̵���� ���� DP�� �����ϴ� ��� ������ ���� �� �ִ�.
//- Failed 1 : dp�迭�� 0���� �ʱ�ȭ�Ͽ� �ð��ʰ��� �߻�.
//- 1. ���� 0�� ����ִ� ����� ���,
//- 2. �̵� ������ ��ΰ� 0�� �� �� �����Ƿ�
//- 3. dp[][]���� 0�� ��쿡 move()�� ��� �����Ѵ�.
//- 4. �̸� �ذ��ϱ� ���� �ʱ� dp[][]�迭�� -1�� �ʱ�ȭ�Ѵ�.
//- Ǯ�� ������ ������ ����.
//- 1. Ǯ�̸� ���� ������ �����Ѵ�.
//- 1.1. �����¿� 4���� ������ ���� dx[], dy[] �迭
//- 1.2. ���̰� ����� map[][] �迭
//- 1.3. �̵� ��� ���� ������ dp[][] �迭
//- 2. move(x, y) �Լ��� (N, M)�� �־� ��� ���� ���Ѵ�.
//- 2.1. (x, y)�� ���� ��� �� dp[y][x]�� ������ ��� dp[y][x]�� �����Ѵ�.
//- 2.2. �������� ���� ���, �����¿� 4���⿡ ���� ������ �����Ѵ�.
//- 2.2.1. ������ ����� ���, �����Ѵ�.
//- 2.2.2. ���� �������� �۰ų� ���� ���, �̵��Ұ����� ����̹Ƿ� �����Ѵ�.
//- 2.2.3. �� ���� ��� move(nx, ny)�� pathSum�� ���Ѵ�.
//- 2.3. dp[y][x]�� pathSum�� �����ϰ� �����Ѵ�.
//- 3. dp[M][N]�� ���� ����Ѵ�.


#include <iostream>

using namespace std;

#define MAP_MAX 501

int Y;		// M
int X;		// N
int map[MAP_MAX][MAP_MAX];
int dp[MAP_MAX][MAP_MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void init() {
	cin >> Y >> X;
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			cin >> map[y][x];
			dp[y][x] = -1;
		}
	}

	dp[1][1] = 1;
}

int move(int x, int y) {
	if (dp[y][x] != -1) return dp[y][x];
	int pathSum = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || nx > X || ny <= 0 || ny > Y) continue;
		if (map[y][x] >= map[ny][nx]) continue;
		pathSum += move(nx, ny);
	}

	return dp[y][x] = pathSum;
}

//void print_map() {
//	for (int y = 1; y <= Y; y++) {
//		for (int x = 1; x <= X; x++) {
//			cout << dp[y][x] << " ";
//		}
//		cout << endl;
//	}
//}

void solution() {
	init();
	move(X, Y);
	//print_map();
	cout << dp[Y][X] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}