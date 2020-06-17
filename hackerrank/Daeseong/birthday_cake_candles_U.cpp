// start 5:57
// end : 6:16

// 남아있는 초를 세는 줄 알았는데 반대였다. 꺼뜨린 초의 수로
// 정렬된 배열 중 가장 큰 정수의 갯수를 출력하면 된다.

#include <iostream>
#include <queue>

using namespace std;

int result;
int N;
priority_queue<int> candles;

void input() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		candles.push(temp);
	}
}

void blow_taller(int target) {
	int temp;

	while (!candles.empty()) {
		temp = candles.top();
		if (temp != target) break;
		candles.pop();
	}

	result = candles.size();
}

void solve() {
	input();
	blow_taller(candles.top());

	cout << N - result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	solve();
	return 0;
}