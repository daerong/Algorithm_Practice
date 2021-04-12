//Solution
//- 사다리타기 문제이지만 도착지에서 역으로 출발지를 찾아가는 방식의 문제
//- map 전체에 2는 하나뿐이므로 2를 기준으로 path를 따라간다면 문제를 쉽게 풀 수 있다.
//- 이론적 접근은 다음과 같다.
//- 1. 2를 시작으로 다음을 수행한다.
//- 2. 좌우에 1이 없다면 y - 1로 이동한다.
//- 3. 좌우에 1이 있다면 0 이전까지 죽 이동한다.
//- 4. y = 0이 되는 지점에서의 x를 출력한다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 세팅한다.
//- 1.1.map[][] : map 사이즈는 100 x 100으로 고정.주어진 값을 입력한다.
//- 1.2.goal : 2의 x위치. (y는 MAP_SIZE - 1)
//- 2. path(x, y, dir)를 수행한다.
//- 2.1.dir == 0인 경우,
//-2.1.1.좌측(map[y][x - 1])의 값이 1인 경우, path(x - 1, y, dir = -1)
//- 2.1.2.우측(map[y][x + 1])의 값이 1인 경우, path(x + 1, y, dir = 1)
//- 2.1.3.좌우 둘다 0인 경우, path(x, y - 1, dir = 0)
//- 2.2.dir == -1인 경우,
//-2.2.1.좌측(map[y][x - 1])의 값이 1인 경우, path(x - 1, y, dir = -1)
//- 2.2.2.그 외의 경우, path(x, y - 1, dir = 0)
//- 2.3.dir == 1인 경우,
//-2.3.1.우측(map[y][x + 1])의 값이 1인 경우, path(x + 1, y, dir = 1)
//- 2.3.2.그 외의 경우, path(x, y - 1, dir = 0)
//- 3. y == 0일 때, x의 값을 출력한다.

#include <iostream>

using namespace std;

#define MAP_SIZE 100

int map[MAP_SIZE + 1][MAP_SIZE + 1];
int goal_x;
int answer;

void init() {
	for (int y = 0; y < MAP_SIZE; y++) {
		for (int x = 0; x < MAP_SIZE; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) goal_x = x;
		}
	}
}

void path(int x, int y, int dir) {
	if (y == 0) {
		answer = x;
		return;
	}

	switch (dir) {
	case -1:
		if (x == 0 || map[y][x - 1] == 0) {
			path(x, y - 1, 0);
		}
		else {
			path(x - 1, y, -1);
		}
		break;
	case 1:
		if (x == MAP_SIZE - 1 || map[y][x + 1] == 0) {
			path(x, y - 1, 0);
		}
		else {
			path(x + 1, y, 1);
		}
		break;
	case 0:
		if (x > 0 && map[y][x - 1] == 1) {
			path(x - 1, y, -1);
		}
		else if (x < MAP_SIZE - 1 && map[y][x + 1] == 1) {
			path(x + 1, y, 1);
		}
		else {
			path(x, y - 1, 0);
		}
		break;
	}
}

void solution() {
	int turn;
	for (int i = 0; i < 10; i++) {
		cin >> turn;
		init();
		path(goal_x, MAP_SIZE - 1, 0);
		cout << "#" << turn << " " << answer << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}