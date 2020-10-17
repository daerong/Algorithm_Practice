//Solution
//- ���̷����� ��ġ�� �� �ִ� ��ġ�� �������� �����ؾ� �ϹǷ� Combination�� ���� �� �ֳİ� �߿�.
//- ���̷����� Ȯ���� bfs�� �̿��Ѵ�.
//- ������ Ǯ�̰����� ������ ����.
//- 1. �־��� ������ �⺻ �����͸� �����Ѵ�.
//- 1.1. map[y][x]���� �� ������ ��´�.
//- 1.2. map[y][x]�� 0�̳� 2�� ��� empty_cnt�� ������Ų��. (empty_cnt = ���̾ƴ� ������ ����)
//- 1.3. virus_init�� �ʱ� ���̷��� ��ġ�� �����Ѵ�.
//- 2. virus_init�� ���� Combination�� �����Ѵ�. 
//- 2.1. ���� ������ M���� �Ǹ� 3.�� �����Ѵ�.
//- 3. expand() �Լ����� ���̷����� ��� Ȯ��Ǳ������ �ð��� ���Ѵ�.
//- 3.1. queue<VIRUS>�� 2.1.���� ������ ���̷��� ������ ��´�.
//- 3.2. queue�� �� ������ ������ �ݺ��Ѵ�.
//- 3.2.1. ���̷��� ������ empty_cnt�� ���ų� ū ��� time�� �����Ѵ�. (time�� �ʱⰪ 0, ���� �ʱⰪ virus_init�� size)
//- 3.2.2. ���� 4���⿡ ���� ������ �����Ѵ�.
//- 3.2.2.1. ������ ��� ���, �ƹ��͵� �������� ����.
//- 3.2.2.2. ���� ���, �ƹ��͵� �������� ����.
//- 3.2.2.3. �̹� �湮�� ������ ���, �ƹ��͵� �������� ����.
//- 3.2.2.4. map[y][x] == 0�� ��� �� ������� ��� ���̷��� ������ 1 ������Ų��.
//- 3.2.2.5. new_queue�� ���� ��ġ�� �߰��Ѵ�.
//- 3.2.3. time�� 1������Ų��.
//- 3.2.4. queue�� new_queue�� �ִ´�.
//- 3.2.5. 3.2.�� ���ư���.
//- 3.3. 3.2.1�� �������� ���� �����̹Ƿ� ���̷����� ��� ������ ���ߴ�. -1�� �����Ѵ�.
//- 4. ��� ���տ� ���� 3.�� �����ϰ� �� �� answer�� ���� ����Ѵ�.
//- 4.1. ��� ���տ� ���� -1�� ���, -1�� ����Ѵ�.
//- 4.2. ������ ����� �ּҰ�. ��, �ִ� Ȯ�� �ð��� ����Ѵ�.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAP_MAX 50
#define VIRUS_MAX 10

typedef struct VIRUS {
	int x;
	int y;
} VIRUS;
vector<VIRUS> virus_init;
vector<VIRUS> virus;
bool virus_map[VIRUS_MAX];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int answer = 99999;

int N;
int M;		// virus vol
int map[MAP_MAX][MAP_MAX];
int empty_cnt;

bool visited[MAP_MAX][MAP_MAX];
void visited_reset() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visited[y][x] = false;
		}
	}
}

int expand(int cnt) {
	int time = 0;
	visited_reset();
	queue<VIRUS> q;
	for (int i = 0; i < virus.size(); i++) q.push(virus[i]);
	while (!q.empty()) {
		if (cnt >= empty_cnt) return time;
		queue<VIRUS> next_q;
		while (!q.empty()) {
			VIRUS temp = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = temp.x + dx[dir];
				int ny = temp.y + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (map[ny][nx] == 1) continue;
				if (visited[ny][nx]) continue;
				if (map[ny][nx] == 0) {
					cnt++;
				}

				visited[ny][nx] = true;
				next_q.push({ nx, ny });
			}
		}

		q = next_q;
		time++;
	}

	return -1;
}

void combination(int target, int cnt) {
	if (cnt >= M) {
		int temp = expand(virus_init.size());
		if (temp != -1) answer = min(answer, temp);
		//for (int i = 0; i < virus.size(); i++) {
		//	cout << "(" << virus[i].x << ", " << virus[i].y << ") ";
		//}
		//cout << endl;
		return;
	}
	if (target >= virus_init.size()) return;


	virus_map[target] = true;
	virus.push_back(virus_init[target]);
	combination(target + 1, cnt + 1);
	virus_map[target] = false;
	virus.pop_back();
	combination(target + 1, cnt);
}

void solution() {
	combination(0, 0);
	if (answer == 99999) answer = -1;
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < VIRUS_MAX; i++) virus_map[i] = false;		// ���� ����

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			switch (map[y][x]) {
			case 2:
				virus_init.push_back({ x, y });
			case 0:
				empty_cnt++;
				break;
			}
		}
	}

	solution();

	return 0;
}