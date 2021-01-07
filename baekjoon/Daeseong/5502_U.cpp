//Solution
//- �縰Ʈ���̶�� ��Ī ���ڿ��� ���ϱ� ���� �߰��� ������ ������ ���ϴ� ����.
//- �̷��� ������ ������ ����.
//- 1. �� ������ ����ϴ� ���ڿ��� �ΰ� �����.
//- 1.1.���� ���ڿ��� str
//- 1.2.���� ���ڿ��� rts�� ����Ѵ�.
//- 2. ���� ������ ���� ������� ���ڿ� max_len�� ���Ѵ�.
//- 2.1.x�� y�� ���� str, rts�� ���� index�̸� 0���� ���� �����Ѵ�.
//- 2.2.str[x] == rts[y]�� ���,
//- 2.2.1.���ڿ��� ���̰� 1 �����ϰ�
//- 2.2.2.������ �ε����� ��� 1 ������Ų��. = > (x + 1, y + 1)
//- 2.3.str[x] != rts[y]�� ���,
//- 2.3.1.������ �ε����� ���� 1 ������Ų��. = > (x + 1, y) && (x, y + 1)
//- 3. �־��� ���ڿ��� ���� N���� max_len�� �� ���� �ٷ� �߰��� ������ �����̴�.
//- Failed 1 : dp[][]�� string���� ������ �޸� �ʰ��� �߻��ߴ�.
//- 1. ����� Ȯ���ϱ� ���� string���� ���������� �޸� �ʰ� �߻�.
//- 2. Ǯ�̿� string�� �ʿ� �����Ƿ� int������ ��ȯ�� �ذ�
//- Ǯ�̰����� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ���� �����Ѵ�.
//- 1.1.str : �־��� ���ڿ�
//- 1.2.rts : str�� �������� �迭�� ���ڿ�
//- 1.3.dp[y][x] : str[x], rts[y] ��ġ������ ���� �縰��� ����
//- 2. y = N - 1, y = N - 1�� �������� expand()�� �����Ͽ� dp[][]�� �����Ѵ�.
//- 2.1.������ ��� ��� ������� 0�� return
//- 2.2.�̹� ������̸� ���� ���, dp[y][x]�� ����
//- 2.3.str[x] == rts[y]�� ���,
//- 2.3.1.dp[y][x]�� expand(x - 1, y - 1) + 1�� �����ϰ�
//- 2.3.2.dp[y][x]�� ���� ����
//- 2.4.str[x] != rts[y]�� ���,
//- 2.4.1.expand(x - 1, y)�� expand(x, y - 1)�� �ִ밪�� ���ϰ�
//- 2.4.2.dp[y][x]�� 2.4.1.���� ���� �ִ밪�� �����ϰ�
//- 2.4.3.dp[y][x]�� ���� ����
//- 3. �� ������ �ݺ��� ��, dp[N - 1][N - 1]�� ���� ����� ����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAP_MAX 5000

int N;
string str;
string rts;
vector<vector<int>> dp;

void init() {
	cin >> N;
	cin >> str;
	rts = str;
	reverse(rts.begin(), rts.end());
	for (int y = 0; y < N; y++) {
		vector<int> line;
		for (int x = 0; x < N; x++) {
			line.push_back(-1);
		}
		dp.push_back(line);
	}
}

int expand(int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (dp[y][x] != -1) return dp[y][x];

	if (str[x] == rts[y]) {
		return dp[y][x] = expand(x - 1, y - 1) + 1;
	}
	else {
		return dp[y][x] = max(expand(x - 1, y), expand(x, y - 1));
	}
}

void print_map() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << dp[y][x] << " ";
		}
		cout << endl;
	}
}

void solution() {
	init();
	cout << N - expand(N - 1, N - 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}