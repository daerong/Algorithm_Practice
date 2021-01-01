//Solution
//- �ʿ��� ũ�Ⱑ ū �����θ� �̵��� ��, �ִ� �̵�ĭ ���� ���ϴ� ����
//- DP
//- �̷��� ������ ������ ����.
//- 1. �ֺ� ���� ���� ū ��쿡�� �̵��ϹǷ� �ܹ������θ� �н��� �׷�����.
//- 2. ������ ������ �̵��� �� �ִ� �ִ� �̵� ĭ���� �α� ���� �ִ� �̵�ĭ �� + 1�̴�.
//- 3. �н��� ��� ���� ������� �����Ƿ� ��� ���� ���� Ȯ���Ѵ�.
//- Ǯ�̴� ������ ����.
//- 1. �ʿ��� ������ �����Ѵ�.
//- 1.1. map[][] : �־��� �� ����, �볪���� ��
//- 1.2. dp[][] : �̵������� �ִ� �̵�ĭ ��
//- 1.2.1. dp[][]�� -1�� �ʱ�ȭ �Ѵ�.
//- 1.3. answer : map�� ��� ������ ���� �ִ� �̵�ĭ ��
//- 1.4. dx[], dy[] : �����¿� �̵��� ���� ����
//- 2. move()�Լ��� ��� ���� ���� �ִ� �̵�ĭ ���� ���Ѵ�.
//- 2.1. dp[][]�� -1�� �ƴ� ���, dp[][] ���� �����Ѵ�.
//- 2.2. �����¿� 4���⿡ ���� ������ �����Ѵ�.
//- 2.2.1. ���� ����� �ش� ������ �����Ѵ�.
//- 2.2.2. ���� ������ �۰ų� ���� ���, �ش� ������ �����Ѵ�.
//- 2.2.3. �� ���� ���, �ش� ���⿡ ���� move()�� ���Ѵ�. (��ͻ��)
//- 2.2.4. maxPath�� ���Ͽ� 4���⿡ ���� �ִ밪 maxPath�� �����Ѵ�.
//- 2.3. dp[y][x]�� 2.2.3.���� ���� maxPath�� 1�� ���� maxPath + 1�� �����Ѵ�.
//- 2.4. dp[y][x]�� answer���� ū ��� answer�� �����Ѵ�.
//- 3. answer ���� ����Ѵ�.


#include <iostream>
#include <algorithm>

using namespace std;

#define MAP_MAX 501

int N;
int map[MAP_MAX][MAP_MAX];
int dp[MAP_MAX][MAP_MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int answer;

void init() {
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
			dp[y][x] = -1;
		}
	}
}

int move(int x, int y) {
	if (dp[y][x] != -1) return dp[y][x];
	int maxPath = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
		if (map[ny][nx] <= map[y][x]) continue;
		maxPath = max(maxPath, move(nx, ny));
	}

	dp[y][x] = maxPath + 1;
	answer = max(answer, dp[y][x]);

	return dp[y][x];
}

void solution() {
	init();
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			move(x, y);
		}
	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}