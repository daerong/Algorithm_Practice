#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define PG_MAX 501

int K;
int dp[PG_MAX][PG_MAX];

void init() {
	cin >> K;
	for (int k = 0; k < K; k++) {
		cin >> dp[0][k];
	}
}
void end() {
	for (int y = 1; y < K; y++) {
		for (int x = y; x < K; x++) {
			dp[y][x] = 0;
		}
	}
}

void print() {
	for (int y = 0; y < K; y++) {
		for (int x = 0; x < K; x++) {
			cout << dp[y][x] << " ";
		}
		cout << endl;
	}
}

void expand() {
	for (int y = 1; y < K; y++) {
		for (int x = y; x < K; x++) {
			cout << y - 1 << ", " << x - 1 << endl;
			cout << "0, " << x << endl;
			cout << y - 1 << ", " << x << endl;
			cout << "0, " << x - y << endl;
			dp[y][x] = min(dp[y - 1][x - 1] + dp[0][x], dp[y - 1][x] + dp[0][x - y]);
			print();
		}
	}
}



void solution() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		expand();
		print();
		end();
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}