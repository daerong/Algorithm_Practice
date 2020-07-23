/*Solution
- Using pow()
- If each digits can divide given number, increase answer.*/ 

#include <iostream>
#include <math.h>

using namespace std;
long long num;
long long digits[9];

void input(){
	cin >> num;
	long long temp = num;
	for (int i = 8; i >= 0; i--) {
		digits[i] = temp / pow(10, i);
		temp = temp - digits[i] * pow(10, i);
	}
}

int solution() {
	int cnt = 0;
	for (int i = 8; i >= 0; i--) {
		if (digits[i] != 0) {
			if (num % digits[i] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

void solve() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		input();
		cout << solution() << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}