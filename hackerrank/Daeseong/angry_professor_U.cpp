// start : am 10:54
// end : am 11:08

// Find the number of studens out of limit in class.

#include <iostream>

using namespace std;

int T;

void entrance(int N, int K) {
	int temp;
	int cnt = 0;
	for (int n = 0; n < N; n++) {
		cin >> temp;
		if (temp <= 0) cnt += 1;
	}

	// cnt over threathold
	if (cnt < K) cout << "YES" << endl;
	else cout << "NO" << endl;
}

void solve() {
	cin >> T;
	int N;
	int K;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;
		entrance(N, K);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}