#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int answer = 0;
int N;
int Cx;
int Cy;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
double constantX[] = { 0.01, 0.01, 0.02, 0.02, 0.05, 0.07, 0.07, 0.1, 0.1 };
int xLocate[4][9] = { { 1, 1, 0, 0, -2, 0, 0, -1, -1 }, {-1, 1, -2, 2, 0, -1, 1, -1, 1}, {-1, -1, 0, 0, 2, 0, 0, 1, 1}, {1, -1, 2, -2, 0, 1, -1, 1, -1} };
int yLocate[4][9] = { { 1, -1, 2, -2, 0, 1, -1, 1, -1 }, {-1, -1, 0, 0, 2, 0, 0, 1, 1}, {-1, 1, -2, 2, 0, -1, 1, -1, 1}, {1, 1, 0, 0, -2, 0, 0, -1, -1} };

vector<vector<int>> input() {
	vector<vector<int>> map;
	cin >> N;
	Cx = Cy = N / 2;
	int temp;
	for (int y = 0; y < N; y++) {
		vector<int> line;
		for (int x = 0; x < N; x++) {
			cin >> temp;
			line.push_back(temp);
		}
		map.push_back(line);
	}

	return map;
}

void scatter(int target, vector<vector<int>>& map, int dir) {
	int sum = 0;

	map[Cy][Cx] = 0;

	for (int i = 0; i < 9; i++) {
		int vol = target * constantX[i];
		int nx = Cx + xLocate[dir][i];
		int ny = Cy + yLocate[dir][i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) answer += vol;
		else map[ny][nx] += vol;
		sum += vol;
	}

	int nnx = Cx + dx[dir];
	int nny = Cy + dy[dir];
	int alpha = target - sum;
	if (nnx < 0 || nnx >= N || nny < 0 || nny >= N) answer += alpha;
	else map[nny][nnx] += alpha;
}

void solve() {
	vector<vector<int>> map = input();
	int dir = 0;
	int xMin, xMax, yMax, yMin;
	yMax = yMin = xMax = xMin = N / 2;

	for (int i = 0; i < N * N - 1; i++) {
		Cx += dx[dir];
		Cy += dy[dir];
		scatter(map[Cy][Cx], map, dir);

		if (Cx < xMin) {
			xMin = Cx;
			dir = (dir + 1) % 4;
		}
		else if (Cx > xMax) {
			xMax = Cx;
			dir = (dir + 1) % 4;
		}
		else if (Cy < yMin) {
			yMin = Cy;
			dir = (dir + 1) % 4;
		}
		else if (Cy > yMax) {
			yMax = Cy;
			dir = (dir + 1) % 4;
		}
	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}