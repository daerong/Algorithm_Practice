//Solution
//- 인구 차이가 L <= diff <= R인 모든 블럭을 연결하는 문제다.이후 각블럭에 대해 합의 평균을 취해야 한다.
//- union이 parent chain 가운데서 발생할 경우, 하위 요소가 다른 parent 요소를 가지게 되므로 꼭 한번 더 확인하자.
//- 풀이 과정은 다음과 같다.
//- 1. 주어진 인구 배열을 map[y][x]에 저장한다.
//- 2. 사용할 변수들을 초기화한다.
//- 2.1.parent[y * N + x]를 y * N + x로 초기화
//- 2.2.sum[y * N + x]를 map[y][x]로 초기화
//- 2.3.cnt[y * N + x]를 1로 초기화
//- 2.4.visited[y][x]를 false로 초기화
//- 3. opening(x, y) 함수에서 국경을 연다.
//- 모든 x, y에 대해 최소 한번은 수행한다. (이미 연결된 나라에서도 다른 나라로 연결이 발생할 수 있음)
//- 3.1.방문 여부를 체크한다.
//- 3.1.1.방문한 경우, 진행하지 않는다.
//- 3.1.2.방문하지 않은 경우, 아래를 수행한다.
//- 3.2.이웃한 4방향의 나라에 대해 다음을 수행한다.
//- 3.2.1.현재 나라와 이웃한 나라의 차이 diff를 구한다.
//- 3.2.2.L < diff < R인 경우, 더 작은 index를 가진 parent로 union을 실행한다.
//- 3.2.2.1.공통 parent로 cnt를 합한다.
//- 3.2.2.2.공통 parent로 sum을 합한다.
//- 3.2.2.3.공통 parent를 일치시킨다.
//- 3.3.이웃한 4방향의 나라에 대해 3을 반복한다.


#include <iostream>
#include <vector>

	using namespace std;

#define N_MAX 50

int N;		// 맵 MAX
int L;		// 인구차이 L이상
int R;		// 인구차이 R이하

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int map[N_MAX][N_MAX];
int parent[N_MAX * N_MAX];
int sum[N_MAX * N_MAX];
int cnt[N_MAX * N_MAX];
bool visited[N_MAX][N_MAX];

int opening_cnt;

int get_parent(int target) {
	if (parent[target] == target) return target;

	return parent[target] = get_parent(parent[target]);
}

void opening(int x, int y) {
	if (opening_cnt == N * N) return;
	if (visited[y][x]) return;
	visited[y][x] = true;
	opening_cnt++;

	int id = y * N + x;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		int nid = ny * N + nx;

		int diff = abs(map[y][x] - map[ny][nx]);
		if (diff >= L && diff <= R) {
			int Parent = get_parent(id);
			int nParent = get_parent(nid);
			if (Parent > nParent) {
				cnt[nParent] += cnt[Parent];
				cnt[Parent] = 0;
				sum[nParent] += sum[Parent];
				sum[Parent] = 0;
				parent[Parent] = nParent;
			}
			else if (Parent < nParent) {
				cnt[Parent] += cnt[nParent];
				cnt[nParent] = 0;
				sum[Parent] += sum[nParent];
				sum[nParent] = 0;
				parent[nParent] = Parent;
			}
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		opening(nx, ny);
	}
}

bool moving() {
	bool check = false;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int Parent = get_parent(y * N + x);
			if (cnt[Parent] != 1) check = true;
			map[y][x] = sum[Parent] / cnt[Parent];
		}
	}

	return check;
}

//void print_map() {
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cout << map[y][x] << " ";
//		}
//
//		cout << endl;
//	}
//}
//
//void print_parent() {
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cout << get_parent(y * N + x) << " ";
//		}
//
//		cout << endl;
//	}
//}

void solution() {
	int moveing_cnt = -1;
	do {
		//print_map();
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				int locate = y * N + x;
				parent[locate] = locate;
				sum[locate] = map[y][x];
				cnt[locate] = 1;
				visited[y][x] = false;
			}
		}
		opening_cnt = 0;
		opening(0, 0);
		//print_parent();
		moveing_cnt++;
	} while (moving());

	cout << moveing_cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	solution();

	return 0;
}