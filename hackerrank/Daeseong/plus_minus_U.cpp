// start : pm 10:20
// end : pm 10:35
// cout 특징
// 1. 소숫점 이하 6째자리까지만 표시(반올림)
// 2. 소수점 이하 의미없는 0 표시안함

#include <iostream>

using namespace std;

double result[3];	// +, -, 0

int N;
int *num_arr;

void input() {
	cin >> N;
	num_arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num_arr[i];
	}
}

void divide_section() {
	for (int i = 0; i < N; i++) {
		if (num_arr[i] == 0) {
			result[2] += 1;
		}
		else if (num_arr[i] > 0) {
			result[0] += 1;
		}
		else {
			result[1] += 1;
		}
	}
}

void solve() {
	input();

	divide_section();
	
	cout << result[0] / N << endl;
	cout << result[1] / N << endl;
	cout << result[2] / N << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}