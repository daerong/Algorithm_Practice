//Solution
//- �ܸ�~�ܸ��� ������ ��, ���� ū ����ġ�� ���� path�� ã�� ����.
//- �̷��� ������ ����.
//- 1. �ܸ����� �ܸ������� ����ġ �� �߿� ���� �ִ�.
//- 1.1.���� ������ Ȯ���� �� �ִ� ���, �ִ밡 �� �� ����.
//- 2. �ܸ����� ����� �� �ִ� ������ ���� ������ �����̴�.
//- 3. ��� ��忡 ���� DFS Ȯ���� �õ��ϸ� �ִ� ����ġ ���� ���� �� �ִ�.
//- Failed 1 : ����Ʈ���� �����ϰ� Ǯ�������� Ʋ�ȴ�.
//- 1. �¿� �������� ū���� �����ϸ� Ȯ����� �ð����⵵�� ������ �⺻������ ����Ʈ���� �ƴϾ ���Ұ�.
//- 2. ������ ������ ���ٰ� �ϸ� ���ͷ� �����Ͽ� ���� ������� Ȯ���Ű�� �ȴ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1.node : N���� ��忡 ���� ������ vector<>
//- 1.2.visited : ��忡 ���� �湮���θ� üũ�� �迭
//- 1.3.answer : ���� ����ġ ���� �ִ밪
//- 2. ��� ��忡 ���� ������ �����Ѵ�.
//- 2.1. dfs() �Լ��� node�� �����Ѵ�.
//- 2.2. ����� ��带 ���� dfs()�� Ȯ���Ѵ�.
//- 2.3. ���̻� ������ �� ���� ��, answer�� �ִ밪���� ������Ʈ�Ѵ�.
//- 3. answer�� ����Ѵ�.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 10001

typedef struct NODE {
	int num;
	int wgt;
} NODE;

int N;
vector<NODE> node[N_MAX];
bool visited[N_MAX];
int answer;

void init() {
	cin >> N;
	int a, b, w;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> w;
		node[a].push_back({ b, w });
		node[b].push_back({ a, w });
	}
}

void dfs(int target, int sum) {
	visited[target] = true;
	for (int i = 0; i < node[target].size(); i++) {
		if (visited[node[target][i].num]) continue;
		dfs(node[target][i].num, sum + node[target][i].wgt);
	}
	answer = max(answer, sum);
	visited[target] = false;
}

void solution() {
	init();
	for (int i = 1; i <= N; i++) dfs(i, 0);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}