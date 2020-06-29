// start : am 2:41
// end : am 2:50

// find maximum summation under limit.

#include <iostream>
#include <algorithm>

using namespace std;

int result = -1;

int b, n, m;
int* keyboard;
int* drives;

void solution() {
	cin >> b >> n >> m;
	keyboard = new int[n];
	drives = new int[m];
	for (int i = 0; i < n; i++) {
		cin >> keyboard[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> drives[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (keyboard[i] + drives[j] <= b) {
				result = max(result, keyboard[i] + drives[j]);
			}
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}