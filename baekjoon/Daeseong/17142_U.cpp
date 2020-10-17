//Solution
//- 바이러스가 위치할 수 있는 위치의 조합으로 실행해야 하므로 Combination을 만들 수 있냐가 중요.
//- 바이러스의 확산은 bfs를 이용한다.
//- 문제의 풀이과정은 다음과 같다.
//- 1. 주어진 정보로 기본 데이터를 세팅한다.
//- 1.1. map[y][x]에는 맵 정보를 담는다.
//- 1.2. map[y][x]가 0이나 2인 경우 empty_cnt를 증가시킨다. (empty_cnt = 벽이아닌 공간의 갯수)
//- 1.3. virus_init에 초기 바이러스 위치를 저장한다.
//- 2. virus_init에 대해 Combination을 구성한다. 
//- 2.1. 조합 구성이 M개가 되면 3.을 실행한다.
//- 3. expand() 함수에서 바이러스가 모두 확산되기까지의 시간을 구한다.
//- 3.1. queue<VIRUS>에 2.1.에서 구성한 바이러스 조합을 담는다.
//- 3.2. queue가 빌 때까지 다음을 반복한다.
//- 3.2.1. 바이러스 갯수가 empty_cnt와 같거나 큰 경우 time을 리턴한다. (time의 초기값 0, 갯수 초기값 virus_init의 size)
//- 3.2.2. 인접 4방향에 대해 다음을 수행한다.
//- 3.2.2.1. 범위를 벗어난 경우, 아무것도 수행하지 않음.
//- 3.2.2.2. 벽인 경우, 아무것도 수행하지 않음.
//- 3.2.2.3. 이미 방문한 공간인 경우, 아무것도 수행하지 않음.
//- 3.2.2.4. map[y][x] == 0인 경우 즉 빈공간의 경우 바이러스 갯수를 1 증가시킨다.
//- 3.2.2.5. new_queue에 현재 위치를 추가한다.
//- 3.2.3. time을 1증가시킨다.
//- 3.2.4. queue에 new_queue를 넣는다.
//- 3.2.5. 3.2.로 돌아간다.
//- 3.3. 3.2.1을 수행하지 않은 상태이므로 바이러스가 모두 퍼지지 못했다. -1을 리턴한다.
//- 4. 모든 조합에 대해 3.을 수행하고 난 뒤 answer의 값을 출력한다.
//- 4.1. 모든 조합에 대해 -1인 경우, -1을 출력한다.
//- 4.2. 조합의 결과의 최소값. 즉, 최단 확산 시간을 출력한다.

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

	for (int i = 0; i < VIRUS_MAX; i++) virus_map[i] = false;		// 생략 가능

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