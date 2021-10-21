#include <iostream>
using namespace std;

#define MAP_MAX 51

int answer;
int T;

int X;
int Y;
bool map[MAP_MAX][MAP_MAX];

void input() {
	cin >> Y >> X;
	answer = 0;
	char temp;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> temp;
			switch (temp) {
			case '#':
				answer++;
				map[y][x] = true;
				break;
			case '.':
				map[y][x] = false;
				break;
			}
		}
	}
}

bool fix() {
	if (!answer) return true;
	for (int y = 1; y < Y; y++) {
		for (int x = 1; x < X; x++) {
			if (map[y - 1][x - 1] && map[y - 1][x] && map[y][x - 1] && map[y][x]) {
				map[y - 1][x - 1] = map[y - 1][x] = map[y][x - 1] = map[y][x] = false;
				answer -= 4;
				if (!answer) return true;
			}
		}
	}
	return false;
}

void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		if (fix()) cout << "#" << t << " YES" << endl;
		else cout << "#" << t << " NO" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}