//Solution
//- x를 이동하며 물고기를 건져올리므로 최대 상어 수는 C이다.
//- index를 (1, 1)부터 시작하면 상어 이동 시 연산이 많아짐.
//- Failed 1 : shark 배열을 사용하니 컴파일 에러가 발생함. 로컬은 가능한데 백준에서는 불가능 한듯.
//	- vector<SHARK>를 사용하여 해결.
//= 풀이과정은 다음과 같다.
//- 1. 맵 map[y][x]에는 shark의 index를 vector<SHARK>에는 상어를 각각 넣는다.
//	- 이동거리는 0 ~ 2 * (N - 1)을 반복하여 나타난다. 따라서 그 이상인 경우 모듈러 연산하여 저장한다.
//- 2. x를 이동하며 다음을 수행한다.
//- 2.1. x위치의 상어 중 y가 가장 작은 상어를 잡는다.
//- 2.2. answer에 상어의 크기를 더한다.
//- 2.3. 상어 이동을 시작한다.
//- 2.3.1. ★상어가 구석에 있는 경우, 방향을 반대방향으로 업데이트 한다.
//- 2.3.2. 최종 도착지를 nx, ny로 놓고 다음을 수행한다.
//- 2.3.2.1. nx = 상어.x + 상어.direction_x * 상어.distance;
//- 2.3.2.1.1. nx > 2 * (X - 1)인 경우, 방향이 두번 바뀐다. (원래 방향)
//- 2.3.2.1.2. nx > X - 1인 경우, 방향이 한번 바뀐다. (반대 방향)
//- 2.3.2.1.3. nx < -1 * (X - 1)인 경우, 방향이 두번 바뀐다. (원래 방향)
//- 2.3.2.1.4. nx < 0인 경우, 방향이 한번 바뀐다. (반대 방향)
//- 2.3.2.2. ny = 상어.y + 상어.direction_y * 상어.distance;
//- 2.3.2.2.1. ny > 2 * (Y - 1)인 경우, 방향이 두번 바뀐다. (원래 방향)
//- 2.3.2.2.2. ny > Y - 1인 경우, 방향이 한번 바뀐다. (반대 방향)
//- 2.3.2.2.3. ny < -1 * (Y - 1)인 경우, 방향이 두번 바뀐다. (원래 방향)
//- 2.3.2.2.4. ny < 0인 경우, 방향이 한번 바뀐다. (반대 방향)
//- 2.3.3. map[ny][nx]에 상어가 있는 경우, 더 작은 상어를 제거한다.
//- 2.3.4. 2.로 돌아가 최종 목적지까지 반복한다.
//- 3. answer을 출력한다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAP_MAX 100 + 1

typedef struct SHARK {
	int x;
	int y;
	int dist;
	int dir;
	int size;
	bool die;
} SHARK;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int map[MAP_MAX][MAP_MAX];
vector<SHARK> vec;

int Y;		// 세로
int X;		// 가로
int M;

//void print_map(){
//	cout << "==============" << endl;
//	for (int y = 0; y < Y; y++) {
//		for (int x = 0; x < X; x++) {
//			cout << shark[map[y][x]].size << " ";
//		}
//		cout << endl;
//	}
//}

void move_shark() {
	for (int m = 1; m <= M; m++) map[vec[m].y][vec[m].x] = 0;
	for (int m = 1; m <= M; m++) {
		if (vec[m].die) continue;
		switch (vec[m].dir) {
		case 0:
			if (vec[m].y == 0) vec[m].dir = 2;
			break;
		case 1:
			if (vec[m].x == X - 1) vec[m].dir = 3;
			break;
		case 2:
			if (vec[m].y == Y - 1) vec[m].dir = 0;
			break;
		case 3:
			if (vec[m].x == 0) vec[m].dir = 1;
			break;
		}

		int nx = vec[m].x + dx[vec[m].dir] * vec[m].dist;
		int ny = vec[m].y + dy[vec[m].dir] * vec[m].dist;

		if (nx > 2 * (X - 1)) {
			nx = nx - 2 * (X - 1);
		}
		else if (nx > X - 1) {
			nx = 2 * (X - 1) - nx;
			vec[m].dir = 3;
		}

		if (nx < -1 * (X - 1)) {
			nx = 2 * (X - 1) + nx;
		}
		else if (nx < 0) {
			nx = abs(nx);
			vec[m].dir = 1;
		}

		if (ny > 2 * (Y - 1)) {
			ny = ny - 2 * (Y - 1);
		}
		else if (ny > Y - 1) {
			ny = 2 * (Y - 1) - ny;
			vec[m].dir = 0;
		}

		if (ny < -1 * (Y - 1)) {
			ny = 2 * (Y - 1) + ny;
		}
		else if (ny < 0) {
			ny = abs(ny);
			vec[m].dir = 2;
		}

		vec[m].x = nx;
		vec[m].y = ny;

		if (map[ny][nx] != 0) {
			if (vec[map[ny][nx]].size > vec[m].size) {
				vec[m].die = true;
			}
			else {
				vec[map[ny][nx]].die = true;
				map[ny][nx] = m;
			}
		}
		else {
			map[ny][nx] = m;
		}
	}
}

int solution() {
	int answer = 0;

	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
			if (map[y][x] != 0) {
				answer += vec[map[y][x]].size;
				vec[map[y][x]].die = true;
				break;
			}
		}

		move_shark();
		//print_map();
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vec.push_back({ 0, 0, 0, 0, 0, true });
	cin >> Y >> X >> M;
	for (int m = 1; m <= M; m++) {
		int x, y, s, d, z;
		cin >> y >> x >> s >> d >> z;
		map[y - 1][x - 1] = m;
		switch (d) {
		case 1:
			d = 0;
			s %= 2 * (Y - 1);
			break;
		case 2:
			d = 2;
			s %= 2 * (Y - 1);
			break;
		case 3:
			d = 1;
			s %= 2 * (X - 1);
			break;
		case 4:
			d = 3;
			s %= 2 * (X - 1);
			break;
		}

		vec.push_back({ x - 1 , y - 1, s, d, z, false });
	}

	cout << solution() << endl;

	return 0;
}