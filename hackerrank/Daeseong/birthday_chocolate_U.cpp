// start : pm 5:43
// end : pm 5:51

// 연속되는 수의 합을 구하는 문제

#include <iostream>

using namespace std;

int result;
int N;
int *arr;
int d;
int m;

void input() {
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> d >> m;
}

void solution() {
	int temp;
	for (int i = m - 1; i < N; i++) {
		temp = 0;
		for (int j = 0; j < m; j++) {
			temp += arr[i - j];
		}
		if (temp == d) result++;
	}
}

void solve() {
	input();
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