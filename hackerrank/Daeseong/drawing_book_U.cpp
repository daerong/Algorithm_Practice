// start : pm 12:36
// end : pm 12:51

// 해당 페이지로 이동하는 데 넘겨야하는 페이지 수를 구하는 문제
// 모듈러 연산으로 쉽게 구할 수 있다.
// 뒤에서 넘기는 경우는 두가지 분기로 나누어야 한다.

#include <iostream>
#include <algorithm>

using namespace std;

int result;

int n;
int p;

void input() {
	cin >> n >> p;
}

void turnning_page() {
	int right = p / 2;
	int left;		
	if (n % 2) left = (n - p)/2;
	else left = (n - p + 1)/2;

	result = min(right, left);
}

void solve() {
	input();
	turnning_page();

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}