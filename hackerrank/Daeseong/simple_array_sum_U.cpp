// start : pm 10:15
// end :pm 10:19
// ´Ü¼ø arr µ¡¼À¹®Á¦

#include <iostream>

using namespace std;

int result;
int N;
int *num_arr;

void input() {
	cin >> N;
	num_arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num_arr[i];
	}
}

void addition() {
	for (int i = 0; i < N; i++) {
		result += num_arr[i];
	}
}

void solve() {
	input();
	addition();
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}