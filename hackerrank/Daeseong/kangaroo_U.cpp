// start : pm 9:01
// end : pm 9:15

// DP를 통해 구하는 방법도 있지만 간단한 공식을 유도하여 구할 수 있다
// 매 점프마다 거리가 일정량 좁혀지며 이 값이 시작 거리의 차이와 같아지면 만나는 것이다.
// 다만 예외사항에 대해서는 처리해야한다.
// 1. 1번의 점프거리가 2번의 점프거리보다 작거나 같은경우 둘은 결코 만날 수 없다.

#include <iostream>

using namespace std;

bool result;

int s_1;
int s_2;
int j_1;
int j_2;

void input() {
	cin >> s_1 >> j_1 >> s_2 >> j_2;
}

void jump() {

	int j_diff = j_1 - j_2;
	int s_diff = s_2 - s_1;

	if (j_diff <= 0) {
		cout << "NO";
		return;
	}

	if (s_diff % j_diff) cout << "NO";
	else cout << "YES"; 
}

void solve() {
	input();

	jump();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}