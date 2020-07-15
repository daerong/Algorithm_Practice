#include <iostream>

using namespace std;

#define N_MAX 51

int N;
int arr[N_MAX];

void input() {
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}
}

int connect(int n, int cnt) {
	if (cnt == 4) {
		return n;
	}

	return connect(arr[n], cnt + 1);
}

void solve() {
	input();
	for (int n = 1; n <= N; n++) {
		cout << connect(arr[n], 1) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}