//Solution
//- 이상한 정렬을 수행하는 문제, 배열의 크기에 상관없이 특정위치의 원소의 값을 확인하면 된다.
//- 풀이과정은 다음과 같다.
//- 1. 주어진 3x3 맵을 map[y][x]에 담는다.
//- 2. 주어진 위치의 숫자를 확인하여 map[r][c] == k이면 시행횟수를 리턴한다.
//- 3. 행의 크기 X와 열의 크기 Y를 비교하여 다음을 실행한다.
//- 3.1. Y >= X인 경우, 다음을 수행한다.
//- 3.1.1. 각 행에 대해 1 ~ 100까지 수의 각각의 갯수를 num[] 배열에 담는다.
//- 3.1.2. 각 수를 정렬하기 위해 {숫자, 갯수} 벡터 vec(갯수의 오름차, 숫자의 오름차 정렬)에 담는다.
//- 3.1.3. vec에서 원소를 빼서 각 두개씩 맵에 추가한다. 숫자, 갯수 순서
//- 3.1.4. 각 행에 대해 2.1.3.에서 추가된 최대 갯수를 X로 업데이트한다.
//- 3.2. Y < X인 경우, 다음을 수행한다.
//- 3.2.1. 각 열에 대해 1 ~ 100까지 수의 각각의 갯수를 num[] 배열에 담는다.
//- 3.2.2. 각 수를 정렬하기 위해 {숫자, 갯수} 벡터 vec(갯수의 오름차, 숫자의 오름차 정렬)에 담는다.
//- 3.2.3. vec에서 원소를 빼서 각 두개씩 맵에 추가한다. 숫자, 갯수 순서
//- 3.2.4. 각 열에 대해 2.1.3.에서 추가된 최대 갯수를 Y로 업데이트한다.
//- 3.3. 2.로 돌아가 다시 확인한다.
//- 4. 100번까지 시행 후, 결과를 얻지 못하면 -1을 리턴한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAP_MAX 100

typedef struct UDS {
	int num;
	int vol;
} UDS;
bool compare(UDS a, UDS b) {
	if (a.vol == b.vol) return a.num < b.num;
	else return a.vol < b.vol;
}

int r;		// y
int c;		// x
int k;
int Y;		// y max
int X;		// x max

int map[MAP_MAX][MAP_MAX];
int num[MAP_MAX + 1];
vector<UDS> vec;

void reset_num() {
	for (int i = 1; i <= MAP_MAX; i++) num[i] = 0;
}

//void print_map() {
//	for (int y = 0; y < Y; y++) {
//		for (int x = 0; x < X; x++) {
//			cout << map[y][x] << " ";
//		}
//
//		cout << endl;
//	}
//}

int solution() {
	for (int t = 0; t <= 100; t++) {
		if (map[r][c] == k) return t;

		if (Y >= X) {
			int new_X = 0;
			for (int y = 0; y < Y; y++) {
				reset_num();
				for (int x = 0; x < X; x++) {
					num[map[y][x]] += 1;
					map[y][x] = 0;
				}

				for (int i = MAP_MAX; i > 0; i--) {
					if (num[i] == 0) continue;
					vec.push_back({ i, num[i] });
				}
				sort(vec.begin(), vec.end(), compare);

				int index = 0;
				for (int i = 0; i < vec.size(); i++) {
					if (index >= MAP_MAX) break;
					map[y][index++] = vec[i].num;
					map[y][index++] = vec[i].vol;
				}

				vec.clear();
				if (new_X < index) new_X = index;
			}
			X = new_X;
		}
		else {
			int new_Y = 0;
			for (int x = 0; x < X; x++) {
				reset_num();
				for (int y = 0; y < Y; y++) {
					num[map[y][x]] += 1;
					map[y][x] = 0;
				}

				for (int i = MAP_MAX; i > 0; i--) {
					if (num[i] == 0) continue;
					vec.push_back({ i, num[i] });
				}
				sort(vec.begin(), vec.end(), compare);

				int index = 0;
				for (int i = 0; i < vec.size(); i++) {
					if (index >= MAP_MAX) break;
					map[index++][x] = vec[i].num;
					map[index++][x] = vec[i].vol;
				}

				vec.clear();
				if (new_Y < index) new_Y = index;
			}
			Y = new_Y;
		}

		//print_map();
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	r -= 1;	c -= 1;
	Y = 3;	X = 3;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> map[y][x];
		}
	}

	cout << solution() << endl;

	return 0;
}