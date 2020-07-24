//Solution
//- Using DP.Insert all square numbers in DP array under 10^9.
//- Then, you can get answer in time O(n).

#include <iostream>

using namespace std;

#define N_MAX 100000

long long arr[N_MAX];
long long N;
long long a;
long long b;

void setting() {
	long long i = 1;
	while (i < N_MAX) {
		arr[i] = i * i;
		i += 1;
	}
	N = i;
}

void input() {
	cin >> a >> b;
}

long long solution() {
	 long long start = 0;
	for (long long i = 1; i < N; i++) {
		if (arr[i] >= a) {
			start = i;
			break;
		}
	}

	if (arr[start] > b) return 0;

	long long end = 0;
	for (long long i = start; i < N; i++) {
		if (arr[i] <= b) continue;
		end = i - 1;
		break;
	}

	return end - start + 1;
}

void solve() {
	setting();
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		input();
		cout << solution() << endl;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}