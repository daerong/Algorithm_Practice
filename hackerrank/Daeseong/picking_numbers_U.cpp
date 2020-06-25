// start : pm 5:44
// end : pm 6:00

// find maxmum summation two number near by

#include <iostream>
#include <algorithm>

using namespace std;

int result;
int N;
int arr[100];

void input() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[temp] += 1;
	}
}

void connection() {
	for (int i = 2; i < 100; i++) {
		result = max(result, arr[i - 1] + arr[i]);
	}
}

void solve() {
	input();
	connection();
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}