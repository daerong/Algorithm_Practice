//Solution
//- The answer of this problem exceed variable's storage space.
//- So this problem should be solved using array of variables. 
//- If you want to use cout function, should be use width and fill function together.

#include <iostream>
using namespace std;
#define NUM_MAX 10000000000			// 10^10
#define ARR_MAX 100

long long num[ARR_MAX];

void solve() {
	int N;
	int max_arr = 0;
	num[0] = 1;
	cin >> N;
	for (int n = 1; n <= N; n++) {
		for (int i = max_arr; i >= 0; i--) {
			num[i] *= n;
			if (num[i] >= NUM_MAX) {
				long long temp = num[i] / NUM_MAX;
				num[i + 1] += temp;
				num[i] = num[i] % NUM_MAX;
			}
		}

		if (num[max_arr + 1] > 0) max_arr++;
	}

	if (max_arr == 0) {
		cout << num[max_arr];
	}
	else {
		cout << num[max_arr];

		for (int i = max_arr - 1; i >= 0; i--) {
			cout.width(10);
			cout.fill('0');
			cout << num[i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}