// start : pm 10:18
// translate : pm 10:47
// end : 11:49

// LCM의 범위가 생각보다 크다. int가 아닌 그 이상을 사용해야 정상적으로 해결할 수 있다.
// long long을 사용하여 문제를 해결함


#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int result;

int f_vol;
int s_vol;
int *f_arr;	// 공배수 구할 거
int *s_arr;

void input() {

	cin >> f_vol >> s_vol;
	
	f_arr = new int[f_vol];
	s_arr = new int[s_vol];

	for (int i = 0; i < f_vol; i++) {
		cin >> f_arr[i];
	}

	for (int i = 0; i < s_vol; i++) {
		cin >> s_arr[i];
	}
}

long long LCM() {
	// 최소공배수
	int arr[102] = { 0, };

	for (int i = 0; i < f_vol; i++) {
		int temp = f_arr[i];
		int num = 2;
		int cnt = 0;
		while (temp != 1) {
			if (temp % num) {
				num++;
				cnt = 0;
			}
			else {
				cnt++;
				temp /= num;
				if (temp % num) {
					arr[num] = max(arr[num], cnt);
				}
			}
		}
	}

	long long lcm = 1;
	int cnt;
	for (int i = 1; i <= 100; i++) {
		cnt = arr[i];
		if (cnt) {
			//cout << "A : " << i << "^" << cnt << endl;
			lcm *= pow(i, cnt);
		}
	}

	return lcm;
}

void cnt_start(long long lcm) {
	//cout << "B : " << lcm << endl;
	long long temp = lcm;
	bool escape = true;
	bool is_pass;
	while (escape) {
		is_pass = true;
		for (int i = 0; i < s_vol; i++) {
			if (s_arr[i] < temp) {
				escape = false;
				break;
			}
			if (s_arr[i] % temp) {
				is_pass = false;
				break;
			}
		}

		if (escape && is_pass) {
			result += 1;
		}
		temp += lcm;
	}
}

void solve() {
	input();

	cnt_start(LCM());
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}