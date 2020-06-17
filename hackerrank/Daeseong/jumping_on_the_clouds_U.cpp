// cloud는 1, 2칸을 점프할 수 있음.
// 점프한 공간에 1(뇌운)이 아니면 점프가 성공한 케이스
// dfs 시뮬레이션으로 구현

#include <iostream>

using namespace std;

int result = 1000000000;

int N;
int *clouds;

void input() {
	cin >> N;
	clouds = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> clouds[i];
	}
}

void jump(int step, int cnt) {
	if (step == N - 1) {
		// 마지막 구름을 밞으면 최소값 판정 update
		if (result > cnt) result = cnt;
		return;
	}
	else if (step >= N) {
		// 범위를 넘어서면 안됨
		return;
	}

	// 점프 실패하면 나가기
	if (clouds[step] == 1) return;

	// 점프 성공
	cnt++;

	// 두가지 케이스에 대해 재귀
	jump(step + 2, cnt);
	jump(step + 1, cnt);
}

void solve() {
	input();
	jump(0, 0);
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}