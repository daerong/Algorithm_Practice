// start : am 10:39
// end : am 10:49

// It can solved DP algorithm.
// Declear DP_table and insert each case.

#include <iostream>

using namespace std;

#define N_MAX 61

int N;
int DP_tv[N_MAX];

void DP_setting() {
	DP_tv[0] = 1;
	for (int i = 1; i < N_MAX; i++) {
		switch (i % 2) {
		case 0:
			DP_tv[i] = DP_tv[i - 1] + 1;
			break;
		case 1:
			DP_tv[i] = DP_tv[i - 1] * 2;
			break;
		}
	}
}

void solve() {
	DP_setting();

	cin >> N;
	int period;
	for (int n = 0; n < N; n++) {
		cin >> period;
		cout << DP_tv[period] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}