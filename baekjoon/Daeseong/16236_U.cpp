//Solution
//- ���ǿ� �����ϴ� ���� ����� ���� ã�� �̵��ϴ� ����.
//- �ش� ���� ������ ������ ����. 
//- 1. baby_size���� �۴�.
//- 2. �̵� �Ÿ� cnt ���� �ּ�
//- 3. cnt�� ���� ���, y���� �� ���� ��.
//- 4. y�� ���� ���, x���� �� ���� ��.
//- �̵� �ÿ� ������ �� ���� ���� ������ ������ ����.
//- 1. baby_size���� ũ��.
//- ���� ���ǿ� ���� bfs�� ��ȸ�ϸ� �̵��� ����Ǵ� ������ �̵��Ÿ��� ���Ѵ�.
//- Ǯ�̰����� ������ ����.
//- 1. �־��� ���� �޾� map[y][x]�� �����Ѵ�.
//- 2. fish.cnt ���� 999�� �����Ѵ�.		(�̵��� ���� ���� ���, 999�� �����ȴ�.)
//- 3. visited[y][x]�� false�� �ʱ�ȭ�Ѵ�. (distance_update()���� bfs���� ��湮�� ���µ� ���)
//- 4. distance_update(x, y, cnt)�� �����Ѵ�.
//- 4.1. ���� ����� ��ġ{baby_x, baby_y}�� �̵��Ÿ� 0�� queue�� �ִ´�.
//- 4.2. 4.1�� �������� queue�� �ݺ��ϸ� bfs�� �����Ѵ�.
//- 4.3. queue�� front�� �����´�.
//- 4.4. �湮 ���ο� ���� ������ �����Ѵ�.
//- 4.4.1. �湮�� ���, ������ �����Ѵ�.
//- 4.4.2. �湮���� ���� ���, visited[y][x]�� �湮�� üũ�Ѵ�.
//- 4.5. map[y][x]�� 0�� �ƴϸ鼭 baby_size���� ������ ������ �����ϸ� fish�� ������Ʈ (FISH ����ü)
//- 4.5.1. ���� �̵��Ÿ��� Ȯ���Ͽ� ������ �����Ѵ�.
//- 4.5.1.1. fish.cnt���� ���� ���, fish{x, y, cnt}�� ������Ʈ �Ѵ�.
//- 4.5.1.2. fish.cnt�� ���� ���, y�� ���� ���� ������ �����Ѵ�.
//- 4.5.1.2.1. fish.y���� ���� ���, fish{ x, y, cnt }�� ������Ʈ �Ѵ�.
//- 4.5.1.2.2. fish.y�� ���� ���, x�� ���� ���� ������ �����Ѵ�.
//- 4.5.1.2.2.1. fish.x���� ���� ���, fish{ x, y, cnt }�� ������Ʈ �Ѵ�.
//- 4.6. �ֺ� �� ���⿡ ���� ������ �����Ѵ�.
//- 4.6.1. map[y][x]�� ������ ��� ���, ���� ������ �����Ѵ�.
//- 4.6.2. map[y][x]�� ���� baby_size���� �۰ų� ���� ��� queue�� �߰��Ѵ�.
//- 4.6.3. 4.3���� ���ư� �ݺ� �����Ѵ�.
//- 5. fish.cnt ���� ���� ������ �����Ѵ�.
//- 5.1. fish.cnt == 999�� ���, ������ �����ϰ� �� �̵��Ÿ� answer�� return�Ѵ�.
//- 5.2. answer�� fish.cnt�� ���ϰ�{ baby_x, baby_y }�� fish�� ��ġ�� �̵��Ѵ�.
//- 5.3. { baby_x, baby_y } ��ġ�� map[y][x]�� 0�� �ִ´�.
//- 5.4. 2.�� ���ư� �ݺ��Ѵ�.



#include <iostream>
#include <queue>

using namespace std;

#define N_MAX 20

typedef struct FISH {
	int x;
	int y;
	int cnt;
} NEXT;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int answer = 0;
int N;
int map[N_MAX][N_MAX];
bool visited[N_MAX][N_MAX];
queue<FISH> q;
FISH fish;

int baby_x;
int baby_y;
int baby_size = 2;
int eat_cnt = 0;

void distance_update(int x, int y, int cnt) {
	q.push({ x, y, cnt });
	while (!q.empty()) {
		FISH temp = q.front();
		q.pop();

		if (visited[temp.y][temp.x]) continue;
		visited[temp.y][temp.x] = true;

		if (map[temp.y][temp.x] != 0 && map[temp.y][temp.x] < baby_size) {
			if (temp.cnt < fish.cnt) {
				fish.x = temp.x;
				fish.y = temp.y;
				fish.cnt = temp.cnt;
			}
			else if (temp.cnt == fish.cnt) {
				if (temp.y < fish.y) {
					fish.x = temp.x;
					fish.y = temp.y;
				}
				else if (temp.y == fish.y) {
					if (temp.x < fish.x) {
						fish.x = temp.x;
						fish.y = temp.y;
					}
				}
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.x + dx[dir];
			int ny = temp.y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (map[ny][nx] > baby_size) continue;
			q.push({ nx, ny, temp.cnt + 1 });
		}
	}
}

void solution() {
	fish.cnt = 999;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visited[y][x] = false;
		}
	}
	distance_update(baby_x, baby_y, 0);

	while (fish.cnt != 999) {
		answer += fish.cnt;
		baby_x = fish.x;
		baby_y = fish.y;
		map[baby_y][baby_x] = 0;
		eat_cnt++;
		if (baby_size == eat_cnt) {
			baby_size++;
			eat_cnt = 0;
		}

		fish.cnt = 999;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				visited[y][x] = false;
			}
		}
		distance_update(baby_x, baby_y, 0);
	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				baby_x = x;
				baby_y = y;
				map[y][x] = 0;
			}
		}
	}

	solution();

	return 0;
}