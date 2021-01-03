//Solution
//- ���� Ư�� ����Ʈ�� �������� ����� ���� ���ϴ� ����.
//- ������ Ư�̻����� �ִ�.
//- 1. Ư�� �������θ� �̵� �����ؼ� ����.
//- 2. �������� ��� ���� �� ���� �������̽�(ex> �̵� �Ÿ��� ���� ��)�� ����.
//- �̷��� ������ ����.
//- 1. ��δ� �̵��Ÿ��� ª�� ������ �������� �Դ� �����̴�.
//- 1.1. ��� �������� �Ծ�� �ϹǷ� �� ������ ������ �����Ѵ�.
//- 2. n = 0(�����)�� ������ ��� ������ ���� ����� ���� ���Ѵ�.
//- 2.1. n��° ��ġ�� ���� ����� ���� n-1��° ��ġ���� ����� ����� ���̴�.
//- 3. ���������� (X = M, Y = N)��ġ�� ��� ���� ���ϸ� �ȴ�.
//- 4. ���´� ������ ���п� ���� �������� ���� �ڽ��� ����̾�׷��̴�.
//- 4.1. ������ ����� ������ ���� ��θ� ������ �ʾ� ȿ�����̴�.
//Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. dp[][] : -1�� �ʱ�ȭ �� 2���� �迭, ���� ��쿡�� 0�� ����ȴ�.
//- 1.2. items : �̵��ؾ��� ��ġ���� ����. ������ �ٽ��̴�.
//- 1.2.1. ��� ��ġ (1 ,1) ����.
//- 1.2.2. �� �������� ��ġ�� ������ vector.
//- 1.2.3. ���� ��ġ (X, Y) ����
//- 1.2.4. �̵��Ÿ� x + y�� ������������ ����.
//- 2. �����(n = 0)�� ������ ��� items ���п� ���� expand() �Լ��� �����Ѵ�.
//- 2.1. dp[y][x]�� -1�� �ƴ� ��쿡�� dp[y][x]�� ��� �����Ѵ�.
//- 2.1.1. ���� ���, 0�̴�. �̵��� �Ұ��ϹǷ� �״�� ����.
//- 2.1.2. �� ���� ���, �̹� ���� dp[][] ���̹Ƿ� �״�� ����Ѵ�.
//- 2.2. n-1��° ������ x, y�� n��° ������ x, y ������ �Ѿ ���� 0�� �����Ѵ�.
//- 2.2.1. ������ ��� ��δ� ������ �� ����.
//- 2.3. dp[y][x] = dp[y-1][x] + dp[y][x-1]���� ���� ������Ʈ�Ѵ�.
//- 2.3.1. �̴� expand()�Լ��� ��ͷ� �����ߴ�.
//- 3. dp[Y][X]�� ���� �����Ͽ� ���� ���Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAP_MAX 100 + 1

typedef struct LOCATE {
	int x;
	int y;
} LOCATE;
bool compare(LOCATE a, LOCATE b) {
	return a.x + a.y < b.x + b.y;
}

int Y;		// M
int X;		// N
int dp[MAP_MAX][MAP_MAX];		// wall : 0, defalut : -1
vector<LOCATE> items;

void init() {
	int A, B;
	cin >> Y >> X >> A >> B;

	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			dp[y][x] = -1;
		}
	}

	int x = 1, y = 1;
	items.push_back({ x, y });
	for (int i = 1; i <= A; i++) {
		cin >> y >> x;
		items.push_back({ x, y });
	}
	items.push_back({ X, Y });
	sort(items.begin(), items.end(), compare);

	for (int i = 1; i <= B; i++) {
		cin >> y >> x;
		dp[y][x] = 0;
	}
	dp[1][1] = 1;
}

int expand(int x, int y, int end_x, int end_y) {
	if (dp[y][x] != -1) return dp[y][x];
	if (x < end_x || y < end_y) return 0;
	return dp[y][x] = expand(x - 1, y, end_x, end_y) + expand(x, y - 1, end_x, end_y);
}

void solution() {
	init();

	for (int i = 1; i < items.size(); i++) {
		expand(items[i].x, items[i].y, items[i - 1].x, items[i - 1].y);
	}

	cout << dp[Y][X] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}