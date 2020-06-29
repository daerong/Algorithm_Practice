// start : am 11:42
// translate : am 11:47
// stop : pm 12:03
// restart : pm 8:26
// end : pm 8:33

// Find diffrece one number and inverse this.
// And Find case it % K == 0

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int result;
int N;
int K;

void input() {
	int i, j;
	cin >> i >> j >> K;
	N = j - i;
	string str;
	int temp;
	int inv;
	for (int n = 0; n <= N; n++) {
		temp = i + n;
		str = to_string(temp);
		reverse(str.begin(), str.end());			// reverse()
		inv = atoi(str.c_str());
		//cout << temp << ", " << str << endl;
		if (abs(temp - inv) % K == 0) result += 1;
	}
}

void solve() {
	input();
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}