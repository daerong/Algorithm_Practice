#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 10

typedef struct XY {
	int x;
	int y;
} XY;

int X, Y;;
bool map[N_MAX][N_MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
XY blue, red, out;
int answer;

void init() {
	cin >> Y >> X;
	char temp;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> temp;
			if (temp == '#') {
				map[y][x] = false;
			}
			else if (temp == 'R') {
				red.x = x;
				red.y = y;
				map[y][x] = true;
			}
			else if (temp == 'R') {
				blue.x = x;
				blue.y = y;
				map[y][x] = true;
			}
			else if (temp == 'O') {
				out.x = x;
				out.y = y;
				map[y][x] = true;
			}
			else {
				map[y][x] = true;
			}
		}
	}
}

void dfs(XY r, XY b, int t) {
	cout << r.x << ", " << r.y << endl;
	cout << b.x << ", " << b.y << endl;
	if (answer == 1) return;
	if (t >= 1000) return;
	for (int dir = 0; dir < 4; dir++) {
		int nrX = r.x;
		int nrY = r.y;
		while (map[nrY][nrX]) {
			nrX += dx[dir];
			nrY += dy[dir];
			if (nrX == out.x && nrY == out.y) {
				nrX = -999;
				nrY = -999;
				break;
			}
		}
		nrX -= dx[dir];
		nrY -= dy[dir];

		int nbX = r.x;
		int nbY = r.y;
		while (map[nbY][nbX]) {
			nbX += dx[dir];
			nbY += dy[dir];
			if (nbX == out.x && nbY == out.y) {
				nbX = -999;
				nbY = -999;
				break;
			}
		}
		nbX -= dx[dir];
		nbY -= dy[dir];

		if (nbX < 0) continue;
		if (nrX < 0) {
			answer = 1;
			return;
		}
		if (nbX == nrX && nbY == nrY) {
			int Bdist = abs(nbX + nbY - b.x - b.y);
			int Rdist = abs(nrX + nrY - r.x - r.y);
			if (Bdist > Rdist) {
				nbX -= dx[dir];
				nbY -= dy[dir];
			}
			else {
				nrX -= dx[dir];
				nrY -= dy[dir];
			}
		}

		dfs({ nrX, nrY }, { nbX, nbY }, t + 1);
	}
}

void solution() {
	init();
	dfs(red, blue, 1);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}