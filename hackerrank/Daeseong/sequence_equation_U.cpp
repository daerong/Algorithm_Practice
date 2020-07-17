#include <iostream>

using namespace std;

#define N_MAX 51

int N;
int locate[N_MAX];
int num[N_MAX];

void input() {
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> num[n];
		locate[num[n]] = n;
	}
}

int get_result(int target, int cnt) {
	if (cnt == 1) {
		return locate[target];
	}


	return get_result(locate[target], cnt + 1);
}

void solve() {
	input();
	for (int n = 1; n <= N; n++) {
		cout << get_result(n, 0) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}