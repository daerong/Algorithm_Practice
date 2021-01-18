#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 10

typedef struct CAN {
	int x;
	int y;
} CAN;

int N;
int M;
vector<CAN> can;
bool arrU[N_MAX * 2 - 1];
bool arrD[N_MAX * 2 - 1];
int answer;

int getU(int x, int y) {
	return (N - 1) + x - y;
}
int getD(int x, int y) {
	return x + y;
}

void init() {
	cin >> N;
	int temp;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> temp;
			if (temp == 1) can.push_back({ x, y });
		}
	}

	M = can.size();
}

void dfs(int target, int cnt) {
	if (target >= M) {
		answer = max(answer, cnt);
		return;
	}

	int tx = can[target].x;
	int ty = can[target].y;
	int u = getU(tx, ty);
	int d = getD(tx, ty);

	if (arrU[u] || arrD[d]) {
		dfs(target + 1, cnt);
	}
	else {
		arrU[u] = true;
		arrD[d] = true;
		dfs(target + 1, cnt + 1);
		arrU[u] = false;
		arrD[d] = false;
		dfs(target + 1, cnt);
	}
}

void solution() {
	init();
	dfs(0, 0);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}