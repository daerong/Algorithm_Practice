// start : am 3:09
// end : am 3:18

// Find maximum in arr and calculate diffrence with K.

#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
	int N;
	int K;
	int maximum = 0;
	int temp;
	cin >> N >> K;
	for (int n = 0; n < N; n++) {
		cin >> temp;
		maximum = max(maximum, temp);
	}

	if (maximum - K < 0) cout << 0;
	else cout << maximum - K;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}