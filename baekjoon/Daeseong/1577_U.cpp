//Solution
//- (0, 0)���� (M, N)���� �ִ� ����� ������ ���ϴ� ����
//- �������� DP����
//- �̷��� ������ ������ ����.
//- 1. (x, y)������ �̵������� ��������� (x-1, y) + (x, y+1)�̴�.
//- 2. ������ ����� ��ġ���� ������ ��δ� 0���̴�.
//- 3. wall�� ����� �������� ���� ��δ� 0���̴�.
//- 4. �� ������ �ݺ����� ��, dp[M][N]�� ���� ��� �̵������ ���̴�.
//- Failed 1 : dp[][]�� int������ ����.
//- 1. ���� �ʰ�
//- 2. long long���� ��ü
//- Failed 2 : (a, b), (c, d) ��� �Ұ��ϰ� Ǯ��
//- 1. ���� �̵����� ������ ���� ���� �̵��Ұ�.
//- 1.1. �׻� ���� ���� ó���� ������ ����� �� ����. �����ϱ�
//- 2. ���⿡ ���� �̵��Ұ��� ó���Ͽ� �ذ�
//- 2.1. (x, y)���� x-1�� y-1�� ���� ������ �̵� �Ұ����θ� �����ߴ�.
//- 2.2. �� ���������� Ư�� �������θ� �̵��ϹǷ� 2���� ���⿡ ���ؼ��� ����ߴ�.
//- Ǯ�̰����� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. dp[y][x] : (0, 0)���� (x, y) ��ġ���� �ִ� �̵���� ��.
//- 1.2. x_wall[y][x] : (x, y)���� (x-1, y)���� �̵��� �Ұ����� ��� true
//- 1.3. y_wall[y][x] : (x, y)���� (x, y-1)���� �̵��� �Ұ����� ��� true
//- 2. (X, Y)�� �������� expand()�� �����Ͽ� dp[][]�� ä���.
//- 2.1. �ʿ��� ��� ���(x<0 �Ǵ� y<0) 0�� return�Ѵ�.
//- 2.2. dp[][]�� �ʱⰪ -1�� �ƴ� ���, �ش� dp[][] ���� return�Ѵ�.
//- 2.3. dp[][] ���� ������Ʈ�Ѵ�.
//- 2.3.1. ������ ��ο� wall�� ���� ���, dp[y][x] = expand(x - 1, y) + expand(x, y - 1)�̴�.
//- 2.3.2. y���⿡ wall�� �ִ� ���, dp[y][x] = expand(x - 1, y)
//- 2.3.3. x���⿡ wall�� �ִ� ���, dp[y][x] = expand(x, y - 1)
//- 2.3.4. ����⿡ wall�� �ִ� ���, dp[y][x] = 0
//- 3. ������Ʈ�� �Ϸ�� dp[][]���� return�Ѵ�.
//- 4. dp[Y][X]�� ���� ����Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

#define MAP_MAX 100

int X;
int Y;
long long dp[MAP_MAX + 1][MAP_MAX + 1];
long long x_wall[MAP_MAX + 1][MAP_MAX + 1];
long long y_wall[MAP_MAX + 1][MAP_MAX + 1];

void init() {
	cin >> X >> Y;
	for (int y = 0; y <= Y; y++) {
		for (int x = 0; x <= X; x++) {
			dp[y][x] = -1;
			x_wall[y][x] = false;
			y_wall[y][x] = false;
		}
	}

	int K;
	cin >> K;
	int x1, y1, x2, y2;
	for (int k = 0; k < K; k++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int x = max(x1, x2);
		int y = max(y1, y2);
		if (x1 == x2) y_wall[y][x] = true;
		if (y1 == y2) x_wall[y][x] = true;
	}

	dp[0][0] = 1;
}

long long expand(int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (dp[y][x] != -1) return dp[y][x];

	long long path_cnt = 0;
	if (y_wall[y][x] == false) path_cnt += expand(x, y - 1);
	if (x_wall[y][x] == false) path_cnt += expand(x - 1, y);

	return dp[y][x] = path_cnt;
}

void solution() {
	init();
	cout << expand(X, Y) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}