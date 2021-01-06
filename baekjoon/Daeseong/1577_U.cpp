#include <iostream>
#include <algorithm>

using namespace std;

#define MAP_MAX 100

int X;
int Y;
int dp[MAP_MAX + 1][MAP_MAX + 1];
int x_wall[MAP_MAX + 1][MAP_MAX + 1];
int y_wall[MAP_MAX + 1][MAP_MAX + 1];

void init() {
	cin >> X >> Y;
	fill(&dp[0][0], &dp[Y + 1][X + 1], -1);
	fill(&x_wall[0][0], &x_wall[Y + 1][X + 1], false);
	fill(&y_wall[0][0], &y_wall[Y + 1][X + 1], false);

	int K;
	cin >> K;
	int x1, y1, x2, y2;
	for (int k = 0; k < K; k++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int x = max(x1, x2);
		int y = max(y1, y2);
		if (x1 == x2) {
			y_wall[y][x] = true;
		}
		else {
			x_wall[y][x] = true;
		}
	}

	dp[0][0] = 1;
}

int expand(int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (dp[y][x] != -1) return dp[y][x];
	if (x_wall[y][x] && y_wall[y][x]) return dp[y][x] = 0;
	else if (x_wall[y][x]) return dp[y][x] = expand(x, y - 1);
	else if (y_wall[y][x]) return dp[y][x] = expand(x - 1, y);
	else return dp[y][x] = expand(x - 1, y) + expand(x, y - 1);
}

void print_map() {
	for (int y = 0; y <= Y; y++) {
		for (int x = 0; x <= X; x++) {
			cout << dp[y][x] << " ";
		}

		cout << endl;
	}
}

void solution() {
	init();
	print_map();
	cout << expand(X, Y) << endl;
	print_map();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}