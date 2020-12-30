//Solution
//- �־��� ����� ������ ������ ä ������ �켱������ �ٲ㼭 ���� ������� �ּҰ� �Ǵ� ���� ���ϴ� ����
//- �̷��� ������ ������ ����.
//- 1. �־��� ����� ������ ������ ä, �߰� �����Ѵ�.
//- 2. ������ ������ ���� ���� ������� �ִ밡 �Ǵ� ���� ���Ѵ�.
//- 3. ������ ���� �������� �������� ����� ��´�.
//- 3.1. 2.���� ���� ���� ������ ���� �̿��� ū ������ ���� ���� �� �ִ�.
//- 3.2. (��ȭ��)minSum[i][j] = minSum[i][k] + minSum[k + 1][j] + matrix[i] X matrix[j](X�� ��İ�)
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. vector<> matrix : ����� ������ ũ�Ⱑ ����� �迭
//- 1.2. dp[i][j] : i��° ��ĺ��� j��° ��� ������ �ּ� ���� ����� 
//- 2. i�� j�� �̵���Ų��. 
//- 2.1. k�� i ~ j �������� �̵���Ű�� ������ �����Ѵ�.
//- 2.1.1. ���� ���� �¿��� dp[][]���� �̿��� �ּҰ� �Ǵ� �ּ� ���� ������� ���Ѵ�. (��ȭ�� ���)
//- 3. ����� ��� ������ �ش��ϴ� dp[0][N-1]�� ���� ����Ѵ�.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NUM_MAX 2147483647
#define MAP_MAX 500 + 1

vector<pair<int, int>> matrix;
int dp[MAP_MAX][MAP_MAX];

void init() {
	int N;
	cin >> N;

	int r, c;
	for (int n = 0; n < N; n++) {
		cin >> r >> c;
		matrix.push_back(make_pair(r, c));
	}
}

void divide() {
	for (int i = matrix.size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < matrix.size(); j++) {
			dp[i][j] = NUM_MAX;
			for (int k = i; k <= j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[i].first * matrix[k].second * matrix[j].second);
			}
		}
	}
}

void solve() {
	init();
	divide();
	cout << dp[0][matrix.size() - 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}