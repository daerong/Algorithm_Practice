// start : pm 5:54
// end : pm 6:02

// nC2 조합에서 두 수의 합이 특정 갯수인지를 판단하는 문제

#include <iostream>

using namespace std;

int result;
int N;
int k;
int *arr;

void input() {
	cin >> N >> k;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void find_pair() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if ((arr[i] + arr[j])% k == 0) {
				result++;
			}
		}
	}
}

void solve() {
	input();
	find_pair();
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}