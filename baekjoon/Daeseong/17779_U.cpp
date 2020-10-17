//Solution
//- 맵 내부를 주어진 조건으로 5개의 영역으로 나눈뒤 영역의 최대 차이값의 최소값을 구하는 문제.
//- 5개의 영역으로 나누는 것이 가장 어려웠음.
//- 1. 주어진 값으로 map[y][x]을 구성한다.
//- 2. 제일 왼쪽의 선거구 위치를 정한다. LEFT(x, y)
//- 3. 위쪽에 대한 거리 up과 아래쪽에 대한 거리 dn을 정한다.
//- 4. 각 끝점의 원소를 구성한다. 
//- 4.1. UP(x + up, y - up)
//- 4.2. DOWN(x + dn, y + up)
//- 4.3. RIGHT(x + up + dn, y - up + dn)
//- 5. 4.의 정보로 구역별 합을 구한다.
//- 5.1. y < L.y && x <= U.x 이면서 (x + y < L.x + L.y)인 경우, 1번 구역
//- 5.2. x > U.x && y <= R.y 이면서 (x - y > U.x - U.y)인 경우, 2번 구역
//- 5.3. x < D.x && y >= L.y 이면서 (y - x > L.y - L.x)인 경우, 3번 구역
//- 5.4. y > R.y && x >= D.x 이면서 (x + y > R.x + R.y)인 경우, 4번 구역
//- 5.5. 나머지는 4번 구역으로 한다.
//- 6. 구역별 합의 차이의 최대값을 구한다.
//- 7. 2.~6.을 반복하여 최대 차이값의 최소값을 리턴한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 20

int N;
int map[N_MAX][N_MAX];
int sum[6];

vector<int> vec;

int each_sum(pair<int, int> U, pair<int, int> D, pair<int, int> L, pair<int, int> R) {
	for (int i = 1; i <= 5; i++) sum[i] = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (y < L.second && x <= U.first) {
				if (x + y < L.first + L.second) sum[1] += map[y][x];
				else sum[5] += map[y][x];
			}
			else if (x > U.first && y <= R.second) {
				if (x - y > U.first - U.second) sum[2] += map[y][x];
				else sum[5] += map[y][x];
			}
			else if (y > R.second && x >= D.first) {
				if (x + y > R.first + R.second) sum[4] += map[y][x];
				else sum[5] += map[y][x];
			}
			else if (x < D.first && y >= L.second) {
				if (y - x > L.second - L.first) sum[3] += map[y][x];
				else sum[5] += map[y][x];
			}
			else sum[5] += map[y][x];
		}
	}

	for (int i = 1; i <= 5; i++) vec.push_back(sum[i]);
	sort(vec.begin(), vec.end());
	int diff = vec[4] - vec[0];
	vec.clear();

	return diff;
}

int solution() {
	int answer = 1000000000;
	pair<int, int> U;		// x, y
	pair<int, int> D;
	pair<int, int> L;
	pair<int, int> R;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			// 제일 왼쪽 선거구 위치
			for (int up = 1; y - up >= 0; up++) {
				for (int dn = 1; y + dn < N; dn++) {
					L.first = x;			L.second = y;
					U.first = x + up;		U.second = y - up;
					D.first = x + dn;		D.second = y + dn;
					R.first = x + up + dn;	R.second = y - up + dn;
					if (R.first >= N) continue;

					answer = min(answer, each_sum(U, D, L, R));
				}
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	cout << solution() << endl;

	return 0;
}