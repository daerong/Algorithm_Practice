//Solution
//- �� ���θ� �־��� �������� 5���� �������� ������ ������ �ִ� ���̰��� �ּҰ��� ���ϴ� ����.
//- 5���� �������� ������ ���� ���� �������.
//- 1. �־��� ������ map[y][x]�� �����Ѵ�.
//- 2. ���� ������ ���ű� ��ġ�� ���Ѵ�. LEFT(x, y)
//- 3. ���ʿ� ���� �Ÿ� up�� �Ʒ��ʿ� ���� �Ÿ� dn�� ���Ѵ�.
//- 4. �� ������ ���Ҹ� �����Ѵ�. 
//- 4.1. UP(x + up, y - up)
//- 4.2. DOWN(x + dn, y + up)
//- 4.3. RIGHT(x + up + dn, y - up + dn)
//- 5. 4.�� ������ ������ ���� ���Ѵ�.
//- 5.1. y < L.y && x <= U.x �̸鼭 (x + y < L.x + L.y)�� ���, 1�� ����
//- 5.2. x > U.x && y <= R.y �̸鼭 (x - y > U.x - U.y)�� ���, 2�� ����
//- 5.3. x < D.x && y >= L.y �̸鼭 (y - x > L.y - L.x)�� ���, 3�� ����
//- 5.4. y > R.y && x >= D.x �̸鼭 (x + y > R.x + R.y)�� ���, 4�� ����
//- 5.5. �������� 4�� �������� �Ѵ�.
//- 6. ������ ���� ������ �ִ밪�� ���Ѵ�.
//- 7. 2.~6.�� �ݺ��Ͽ� �ִ� ���̰��� �ּҰ��� �����Ѵ�.

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
			// ���� ���� ���ű� ��ġ
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