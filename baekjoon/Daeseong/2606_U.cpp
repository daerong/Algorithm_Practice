//Solution
//- Union - Find�� �������� ����
//- �̷��� ������ ������ ����.
//- 1. a, b�� ����Ǿ� ���� ��, ���� ��ȣ�� ���� �ʿ� �����Ѵ�.
//- 2. a, b�� �ٸ� ��Ʈ��ũ�� ����Ǿ� ���� ��, �θ��� ��ȣ�� ���Ͽ� ���� ��ȣ�� ���� �ʿ� �����Ѵ�.
//- 3. ��ü ��Ʈ��ũ �� 1�� ��ȣ�� ���� ��ǻ���� ���� ���Ѵ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1.parent[] : �ֻ��(��Ʈ��ũ �� �ּҰ��� ���� ��ǻ�� ��ȣ) ��, �θ��� index�� ������ �迭.
//- 1.1.1.�ʱⰪ�� parent[i] = i
//- 1.2.virus[] : ���̷��� ������ ��� �迭
//- 2. expand() �Լ����� union - find�� �����Ѵ�.
//- 2.1.parent(a), parent(b)�� ���Ѵ�.
//- 2.1.1.parent(a) < parent(b) �� ���, parent[b] = a�� �����Ѵ�.
//- 2.1.2.parent(a) > parent(b) �� ���, parent[a] = b�� �����Ѵ�.
//- 3. 2�� PC���� Ȯ���Ͽ� parent(n) == 1�� ��ǻ���� ���� ���Ͽ� ����Ѵ�.

#include <iostream>
#include <vector>
#include <queue>

	using namespace std;

#define N_MAX 101

int N;
int V;
int parent[N_MAX];
vector<vector<int>> virus;

void init() {
	cin >> N >> V;
	for (int i = 1; i <= N; i++) parent[i] = i;
	int a, b;
	for (int i = 0; i < V; i++) {
		cin >> a >> b;
		virus.push_back({ a, b });
	}
}

int get_parent(int target) {
	if (parent[target] == target) return target;
	return parent[target] = get_parent(parent[target]);
}

void expand() {
	for (int i = 0; i < virus.size(); i++) {
		int a = get_parent(virus[i][0]);
		int b = get_parent(virus[i][1]);
		if (a < b) {
			parent[b] = a;
			get_parent(virus[i][1]);
		}
		else if (a > b) {
			parent[a] = b;
			get_parent(virus[i][0]);
		}
	}
}

void solution() {
	init();
	expand();
	int answer = 0;
	for (int i = 2; i <= N; i++) {
		if (get_parent(i) == 1) answer++;
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