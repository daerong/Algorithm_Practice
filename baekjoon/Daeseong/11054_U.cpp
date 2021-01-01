#include <iostream>
#include <algorithm>

using namespace std;

#define VOL_MAX 1000 + 1

int N;
int arr[VOL_MAX];
int l_dp[VOL_MAX];
int r_dp[VOL_MAX];
int answer;

void init() {
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
		l_dp[n] = -1;
		r_dp[n] = -1;
	}
}

void l_dp_update(int target, int cnt) {
	int next = -1;
	l_dp[target] = max(l_dp[target], cnt);

	for (int i = target + 1; i < N; i++) {
		if (arr[target] < arr[i]) {
			if (next == -1) {
				l_dp_update(i, cnt + 1);
				next = arr[i];
			}
			else {
				if (next > arr[i]) {
					l_dp_update(i, cnt + 1);
					next = arr[i];
				}
			}
		}
	}
}
void r_dp_update(int target, int cnt) {
	int next = -1;
	r_dp[target] = max(r_dp[target], cnt);
	answer = max(answer, l_dp[target] + r_dp[target] + 1);

	for (int i = target - 1; i >= 0; i--) {
		if (arr[target] < arr[i]) {
			if (next == -1) {
				r_dp_update(i, cnt + 1);
				next = arr[i];
			}
			else {
				if (next > arr[i]) {
					r_dp_update(i, cnt + 1);
					next = arr[i];
				}
			}
		}
	}
}

void solution() {
	init();
	for (int i = 0; i < N; i++) {
		if (l_dp[i] == -1) l_dp_update(i, 0);

	}
	for (int i = N - 1; i >= 0; i--) {
		if (r_dp[i] == -1) r_dp_update(i, 0);
	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}