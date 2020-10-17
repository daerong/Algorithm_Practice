//Solution
//- 겹쳐졌을 때, 행동에 대해 제대로 설정하면 쉽게 풀 수 있다.
//- Failed 1 : STONE map[y][x] 같은 사용은 로컬에서만 사용가능, 프로그래머스에서는 사용불가하니 2차원 벡터 사용.
//- Failed 2 : 이동하는 돌 밑에 있는 돌은 움직이지 않는다.
//- 풀이과정은 다음과 같다.
//- 1. 입력값으로 기본 값을 세팅한다.
//- 1.1. vector<vector<MAP>> map에는 color 정보를 담는다.
//- 1.2. 돌 정보는 vector<STONE> stones에 담는다.
//- 2. 1부터 1000까지의 turn에 대해 다음을 반복한다.
//- 2.1. 모든 돌에 대해 move()을 수행한다.
//- 2.1.1. 이동할 위치가 막힌 경우, 방향을 바꾼 뒤 다음 이동 위치에 대해 다음을 수행한다.
//- 2.1.1.1. 이동할 위치가 파랑인 경우, 멈춘다.
//- 2.1.1.2. 그 외의 경우, 2.1.3.이나 2.1.4.를 실행한다.
//- 2.1.2. 이동할 위치가 파랑인 경우, 방향을 바꾼 뒤 다음 이동 위치에 대해 다음을 수행한다.
//- 2.1.2.1. 이동할 위치가 막힌 경우, 멈춘다.
//- 2.1.2.2. 이동할 위치가 파랑인 경우, 멈춘다.
//- 2.1.2.3. 그 외의 경우, 2.1.3.이나 2.1.4.를 실행한다.
//- 2.1.3. 이동할 위치가 흰색인 경우, 이동할 위치에 그대로 얹는다.
//- 2.1.4. 이동할 위치가 빨강인 경우, 이동할 위치에 역순으로 얹는다.
//- 2.1.5. 이동한 위치에 돌이 4개 이상인 경우 현재 턴 정보를 return한다.
//- 2.1.6. 2.1.로 돌아가 반복한다.
//- 2.2. 1000이하인 경우 2.를 반복한다.
//- 3. 1000번 시행 후, 종료되지 않으므로 -1을 return한다.


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define N_MAX 12
typedef struct STONE {
	int x;
	int y;
	int dir;
} STONE;

typedef struct MAP {
	int color;			// red 1, blue 2
	vector<int> vec;
};

vector<STONE> stones;
vector<vector<MAP>> map;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N;		// map size
int K;

bool move(int target_id) {
	int x = stones[target_id].x;
	int y = stones[target_id].y;
	int dir = stones[target_id].dir;
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
		if (dir % 2) stones[target_id].dir -= 1;
		else stones[target_id].dir += 1;
		dir = stones[target_id].dir;
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (map[ny][nx].color == 2) return false;
	}
	else if (map[ny][nx].color == 2) {
		if (dir % 2) stones[target_id].dir -= 1;
		else stones[target_id].dir += 1;
		dir = stones[target_id].dir;
		nx = x + dx[dir];
		ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) return false;
		if (map[ny][nx].color == 2) return false;
	}
	if (map[ny][nx].color == 0) {
		int find_id = -1;
		bool finded = false;
		for (int target = 0; target < map[y][x].vec.size(); target++) {
			if (target_id == map[y][x].vec[target]) {
				finded = true;
				find_id = target;
			}
			if (finded) {
				map[ny][nx].vec.push_back(map[y][x].vec[target]);
				stones[map[y][x].vec[target]].x = nx;
				stones[map[y][x].vec[target]].y = ny;
			}
		}
		map[y][x].vec.erase(map[y][x].vec.begin() + find_id, map[y][x].vec.end());
	}
	else if (map[ny][nx].color == 1) {
		int find_id = -1;

		for (int target = map[y][x].vec.size() - 1; target >= 0; target--) {
			if (target_id == map[y][x].vec[target]) {
				map[ny][nx].vec.push_back(map[y][x].vec[target]);
				stones[map[y][x].vec[target]].x = nx;
				stones[map[y][x].vec[target]].y = ny;
				find_id = target;
				break;
			}
			else {
				map[ny][nx].vec.push_back(map[y][x].vec[target]);
				stones[map[y][x].vec[target]].x = nx;
				stones[map[y][x].vec[target]].y = ny;
			}
		}

		map[y][x].vec.erase(map[y][x].vec.begin() + find_id, map[y][x].vec.end());
	}

	if (map[ny][nx].vec.size() >= 4) return true;
	else return false;
}


int solution() {
	for (int turn = 1; turn <= 1000; turn++) {
		for (int k = 1; k < stones.size(); k++) {
			if (move(k)) return turn;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int y = 0; y < N; y++) {
		vector<MAP> line;
		for (int x = 0; x < N; x++) {
			MAP temp;
			cin >> temp.color;
			line.push_back(temp);
		}
		map.push_back(line);
	}

	stones.push_back({ -1, -1, -1 });		// 0 제외하고 사용

	int x, y, dir;
	for (int i = 1; i <= K; i++) {
		cin >> y >> x >> dir;
		map[y - 1][x - 1].vec.push_back(i);
		stones.push_back({ x - 1, y - 1, dir - 1 });
	}

	cout << solution() << endl;

	return 0;
}