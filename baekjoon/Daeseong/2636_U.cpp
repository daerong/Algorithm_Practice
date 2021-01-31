//Solution
//- ������ ����� ó���� �����ϸ� BFS������ ����.
//- �̷��� ������ ������ ����.
//- 1. (0, 0)�� �������� bfs�� �����Ѵ�.
//- 1.1. 0�� ������ queue�� �ְ� Ȯ���Ѵ�.
//- 1.2. 1�� ������ 0���� �ٲ۴�.
//- 2. �� 1�� ������ �����ϸ� ����Ǵ� ������ �����Ѵ�.
//- 3. before�� ���� ������ �����Ѵ�.
//- 4. bfs ����Ƚ���� t�� �����Ѵ�.
//- 5. before�� t�� ����Ѵ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. map : �־��� �������� ���� �迭
//- 1.2. v : ��� ��Ұ� false�� �迭. ���� visited �迭�� �ʱⰪ���� ����Ѵ�.
//- 1.2.1. visited : bfs() �Լ����� �湮 üũ
//- 1.4. num : �ʱ� map�� 1�� ����. ��, ġ���� ����
//- 2. t�� 1�� ������Ű�� ������ �����Ѵ�.
//- 2.1. before�� num�� �����Ѵ�.
//- 2.2. bfs()�� �����Ѵ�.
//- 2.2.1. (0, 0)�� queue�� �ִ´�.
//- 2.2.2. queue���� �ϳ��� ������.
//- 2.2.3. �湮������ 2.2.2.�� �����Ѵ�.
//- 2.2.4. �湮���� �ʾ�����, �湮üũ�� �Ѵ�.
//- 2.2.5. map[y][x]�� 1�̸� ������ �����Ѵ�.
//- 2.2.5.1. map[y][x]�� 0���� �ٲ۴�.
//- 2.2.5.2. num�� 1���ҽ�Ų��.
//- 2.2.6. map[y][x]�� 0�̸� �����¿� 4������ queue�� �߰��Ѵ�.
//- 3. before�� t�� ����Ѵ�.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct NODE {
	int x;
	int y;
} NODE;

int Y;
int X;
vector<vector<bool>> map;
vector<vector<bool>> v;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int num;

void init() {
	cin >> Y >> X;
	int temp;
	vector<bool> vec(X, false);
	for (int y = 0; y < Y; y++) {
		vector<bool> line;
		for (int x = 0; x < X; x++) {
			cin >> temp;
			line.push_back(temp);
			if (temp == 1) num++;
		}
		map.push_back(line);
		v.push_back(vec);
	}
}

void bfs(vector<vector<bool>> visited) {
	queue<NODE> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		NODE temp = q.front();
		q.pop();
		if (visited[temp.y][temp.x]) continue;
		visited[temp.y][temp.x] = true;
		if (map[temp.y][temp.x]) {
			map[temp.y][temp.x] = false;
			num--;
			continue;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.x + dx[dir];
			int ny = temp.y + dy[dir];
			if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
			q.push({ nx, ny });
		}
	}
}

void solution() {
	init();
	int before;
	int t = 0;
	while (num != 0) {
		t++;
		before = num;
		bfs(v);
	}
	cout << t << endl;
	cout << before << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}