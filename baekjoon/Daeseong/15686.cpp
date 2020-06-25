#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 50

int result = 1000000001;

int N;		// 맵사이즈
int M;		// 남길 치킨집 수

int map[N_MAX][N_MAX];

typedef struct LOCATE {
	int x;
	int y;
}LOCATE;

vector<LOCATE> store;
vector<LOCATE> house;

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

void set_vector() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (map[y][x] == 1) house.push_back({ x, y });
			else if (map[y][x] == 2) store.push_back({ x, y });
		}
	}
}

int chicken_length(bool *list, int vol) {
	int sum = 0;		// 도시의 치킨거리

	int house_vol = house.size();
	int hx, hy, sx, sy;
	int cL;

	for (int j = 0; j < house_vol; j++) {
		hx = house[j].x;
		hy = house[j].y;

		int n_min = 99999;

		for (int i = 0; i < vol; i++) {
			if (list[i]) {
				sx = store[i].x;
				sy = store[i].y;

				cL = abs(sx - hx) + abs(sy - hy);
				n_min = min(n_min, cL);
			}
		}

		sum += n_min;
	}

	return sum;
}

void dfs(bool *list, int vol, int n, int cnt) {
	if (n > vol) return;

	//cout << "vol : " << vol << ", n : " << n << ", cnt : " << cnt << endl;

	if (cnt == M) {
		int newL = chicken_length(list, vol);
		//cout << newL << endl;
		result = min(result, newL);
		return;
	}
	
	if (list[n] == false) {
		list[n] = true;
		cnt += 1;
		dfs(list, vol, n + 1, cnt);	
		list[n] = false;
		cnt -= 1;
	}

	dfs(list, vol, n + 1, cnt);
}

void solution() {
	int vol = store.size();
	bool *check = new bool[vol];
	for (int i = 0; i < vol; i++) {
		check[i] = false;
	}
	
	dfs(check, vol, 0, 0);
}

void solve() {
	input();
	set_vector();
	solution();

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}