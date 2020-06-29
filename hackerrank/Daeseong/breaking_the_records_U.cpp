// start : pm 11:54
// end : am 00:02

// 변화지점을 체크하면 됨.

#include <iostream>

using namespace std;

int HS;
int LS;

int *num_arr;
int N;

void input() {
	cin >> N;
	num_arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num_arr[i];
	}
}

void solution() {
	int H = num_arr[0];
	int L = num_arr[0];
	for (int i = 1; i < N; i++) {
		if (H < num_arr[i]) {
			H = num_arr[i];
			HS += 1;
		}
		if (L > num_arr[i]) {
			L = num_arr[i];
			LS += 1;
		}
	}
}

void solve() {
	input();
	solution();
	cout << HS << " " << LS;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}