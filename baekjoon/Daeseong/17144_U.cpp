//Solution
//- 주어진 조건에 맞는 함수를 작성하여 해결할 수 있다.
//- 매개변수에 기존 배열을 복사하기 위해 vector에 담았다.
//- 풀이과정은 다음과 같다.
//- 1. 주어진 배열을 map[y][x]에 담는다.
//- 2. 다음을 T회 반복한다.
//- 2.1. expand() 함수는 복제배열 cp[y][x]를 확인하여 원본배열 map[y][x]을 업데이트한다.
//- 2.1.1. 인접한 4블럭에 대해 해당블럭이 맵 안에 위치하며 공기청정기 위치가 아닐 경우 다음을 수행한다.
//- 2.1.1.1. 해당 위치에 cp[y][x] / 5를 더하고 원래 위치에는 cp[y][x]를 뺀다.
//- 2.2. rotate() 함수는 공기청정기 위치를 기준으로 시계, 반시계 방향으로 맵을 이동시킨다.
//- 2.2.1. 위의 반쪽에 대해 다음을 수행한다.
//- 2.2.1.1. 공기청정기 우측으로 이동하며 이전 위치를 다음위치에 복사한다.
//- 2.2.1.2. 더이상 이동이 불가능한 경우, 윗쪽으로 이동하며 복사한다.
//- 2.2.1.3. 더이상 이동이 불가능한 경우, 왼쪽으로 이동하며 복사한다.
//- 2.2.1.4. 더이상 이동이 불가능한 경우, 아랫쪽으로 이동하며 복사한다.
//- 2.2.1.5. 공기청정기 위치에 도착한 경우, 마지막 값을 삭제한다.
//- 2.2.2. 아래 반쪽에 대해 다음을 수행한다.
//- 2.2.2.1. 공기청정기 우측으로 이동하며 이전 위치를 다음위치에 복사한다.
//- 2.2.2.2. 더이상 이동이 불가능한 경우, 아랫쪽으로 이동하며 복사한다.
//- 2.2.2.3. 더이상 이동이 불가능한 경우, 왼쪽으로 이동하며 복사한다.
//- 2.2.2.4. 더이상 이동이 불가능한 경우, 윗쪽으로 이동하며 복사한다.
//- 2.2.2.5. 공기청정기 위치에 도착한 경우, 마지막 값을 삭제한다.
//- 3. 반복 후 map에 남은 먼지의 갯수를 합하여 출력한다.

#include <iostream>
#include <vector>

using namespace std;

#define M_MAX 50

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int R;		// 세로
int C;		// 가로
int T;
vector<vector<int>> map;
int up_y = -1;
int dn_y = -1;

void expand(vector<vector<int>> cp) {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			int expand_var = cp[y][x] / 5;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
				else if (nx == 0) {
					if (ny == up_y || ny == dn_y) continue;
				}

				map[ny][nx] += expand_var;
				map[y][x] -= expand_var;
			}
		}
	}
}

void rotate(vector<vector<int>> cp) {
	int end_x = 0;
	int end_y = up_y;
	int x = 0;
	int y = up_y;
	int dir = 1;
	do {
		if (x == C - 1 && y == end_y) dir = 0;
		else if (x == C - 1 && y == 0) dir = 3;
		else if (x == 0 && y == 0) dir = 2;

		int next_x = x + dx[dir];
		int next_y = y + dy[dir];
		map[next_y][next_x] = cp[y][x];
		x = next_x;
		y = next_y;
	} while (end_x != x || end_y != y);
	map[y][x] = 0;

	end_x = 0;
	end_y = dn_y;
	x = 0;
	y = dn_y;
	dir = 1;
	do {
		if (x == C - 1 && y == end_y) dir = 2;
		else if (x == C - 1 && y == R - 1) dir = 3;
		else if (x == 0 && y == R - 1) dir = 0;

		int next_x = x + dx[dir];
		int next_y = y + dy[dir];
		map[next_y][next_x] = cp[y][x];
		x = next_x;
		y = next_y;
	} while (end_x != x || end_y != y);
	map[y][x] = 0;
}

//void print_map() {
//	cout << "====================" << endl;
//	for (int y = 0; y < R; y++) {
//		for (int x = 0; x < C; x++) {
//			cout << map[y][x] << " ";
//		}
//		cout << endl;
//	}
//}

int solution() {
	for (int t = 1; t <= T; t++) {
		expand(map);
		rotate(map);
		//print_map();
	}

	int answer = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			answer += map[y][x];
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;
	int temp;
	for (int y = 0; y < R; y++) {
		vector<int> line;
		for (int x = 0; x < C; x++) {
			cin >> temp;

			if (temp == -1) {
				if (up_y == -1) up_y = y;
				else dn_y = y;

				line.push_back(0);
			}
			else line.push_back(temp);
		}
		map.push_back(line);
	}

	cout << solution() << endl;

	return 0;
}