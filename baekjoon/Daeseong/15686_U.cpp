//Solution
//- �־��� ġŲ�� �� M���� ������ ������ ����� ������ �ִܰŸ� ���� ���ϴ� ����
//- �̷��� ������ ������ ����.
//- 1. ���� ġŲ���� �Ÿ��� �ִܰŸ� ������ �����Ѵ�.
//- 1.1.���� �״��, ġŲ���� �������� �����ȴ�.
//- 1.2.���� ġŲ���� �Ÿ��� ������ �ʴ´�.
//- 1.3.���� i��° ���� ���� ��� ġŲ���� �Ÿ��� ������������ ������ �����Ѵ�.
//- 2. ġŲ�� M���� �κ�����(Combination)�� �����Ѵ�.
//- 2.1.index�� ���������� �����ϴ� �Լ��� �̿��ϸ� �ߺ����� ������ �����ϴ�.
//- 3. 1.���� ���� �ִܰŸ������� Ȯ���Ѵ�.
//- 3.1.M���� ���õ��� ���� ���, ���� �ִܰŸ��� Ȯ���Ѵ�.
//- 3.2.M���� ���õ� ���, �ִܰŸ��� �����Ѵ�.
//- 3.3.��� ���� ���� �ִܰŸ� ���� ���Ѵ�.
//- 4. ��� ���տ� ���� 3.3.�� �ּҰ��� ����Ѵ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ���� �����Ѵ�.
//- 1.1.dist[i][j] : i��° ���� �������� ����� ġŲ ������ ���ĵ� ġŲ�� �迭. (j�� 0�� ��, ���� �����)
//- 1.2.vector<LOCATE> house : ���� x, y ��ġ�� ��ϵ� �迭
//- 1.3.vector<LOCATE> store : ġŲ���� x, y ��ġ�� ��ϵ� �迭
//- 1.4.answer : ġŲ�Ÿ� ���� �ּҰ�
//- 2. combination(int target, int check, int cnt) �Լ��� ���� M���� ���Ҹ� ���� ġŲ�� ������ �����Ѵ�.
//- 2.1.cnt�� M�� ���, ������ �����Ѵ�.
//- 2.1.1.get_chicken_len() �Լ��� ġŲ�Ÿ� ���� ���Ѵ�.
//- 2.1.1.1.��� ���� ���� ������ �����Ѵ�.
//- 2.1.1.2.i��° ���� ���� j�� 0���� ������Ű�� �ִ� �Ÿ��� Ȯ���Ѵ�.
//- 2.1.1.2.1.j��ġ�� M���� ���ԵǴ����� check�� j��° ��Ʈ�� ���ԵǾ��� �� Ȯ���ϸ� �ȴ�.
//- 2.1.1.2.2.j�� 0�� �� �ּ��̸� �ļ����� ���� ���� ���Ѵ�.
//- 2.1.1.3.��� �������� ġŲ�� �ִܰŸ��� ���� ���Ѵ�.
//- 2.1.2. 2.1.1.���� ���� ġŲ�Ÿ� �հ� answer�� �ּҰ��� answer�� �����Ѵ�.
//- 3. answer�� ����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 50
#define M_MAX 13

typedef struct LOCATE {
	int x;
	int y;
} LOCATE;
typedef struct DIST {
	int store_id;
	int dist;
} DIST;
bool compare(DIST a, DIST b) {
	return a.dist < b.dist;
}

int N;
int M;
vector<vector<DIST>> dist;
vector<LOCATE> house;
vector<LOCATE> store;
int answer;

void init() {
	cin >> N >> M;
	int temp;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> temp;
			if (temp == 1) house.push_back({ x, y });
			else if (temp == 2) store.push_back({ x, y });
		}
	}

	answer = 2147483647;

	int len;
	for (int i = 0; i < house.size(); i++) {
		vector<DIST> line;
		for (int j = 0; j < store.size(); j++) {
			len = abs(house[i].x - store[j].x) + abs(house[i].y - store[j].y);
			line.push_back({ j, len });
		}
		sort(line.begin(), line.end(), compare);
		dist.push_back(line);
	}
}

int get_chicken_len(int check) {
	int sum = 0;
	for (int i = 0; i < dist.size(); i++) {
		for (int j = 0; j < dist[i].size(); j++) {
			if (check & (1 << dist[i][j].store_id)) {
				sum += dist[i][j].dist;
				break;
			}
		}
	}

	return sum;
}

void combination(int target, int check, int cnt) {
	if (cnt == M) {
		answer = min(answer, get_chicken_len(check));
		return;
	}

	if (target >= store.size()) return;

	combination(target + 1, check | (1 << target), cnt + 1);
	combination(target + 1, check, cnt);
}

void solution() {
	init();
	combination(0, 0, 0);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}