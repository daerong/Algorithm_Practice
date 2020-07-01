// start : pm 7:18
// end : 

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define N_MAX 100
#define STRING_SIZE 1000

// U, R, D, L
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int T;
int N;
int deep[N_MAX][N_MAX];
bool visited[N_MAX][N_MAX];
int min_deep;

char inputString[STRING_SIZE];

//파일 출력 (읽기)
ifstream inFile("input.txt");

void input() {
	inFile.getline(inputString, STRING_SIZE);

	N = stoi(inputString);

	for (int y = 0; y < N; y++) {
		inFile.getline(inputString, STRING_SIZE);
		for (int x = 0; x < N; x++) {
			deep[y][x] = inputString[x] - '0';
		}
	}
}

int first_check() {
	int cnt = 0;
	for (int x = 0; x < N; x++) {
		cnt += deep[0][x];
	}
	for (int y = 1; y < N; y++) {
		cnt += deep[y][N - 1];
	}

	return cnt;
}

void move(int nx, int ny, int cnt) {
	if (nx == N - 1 && ny == N - 1) {
		min_deep = min(min_deep, cnt);
		return;
	}

	if (cnt >= min_deep) return;

	if (visited[ny][nx]) return;

	if (nx >= N) return;
	if (nx < 0) return;
	if (ny >= N) return;
	if (ny < 0) return;

	visited[ny][nx] = true;

	int next_x;
	int next_y;
	for (int i = 0; i < 4; i++) {
		next_x = nx + dx[i];
		next_y = ny + dy[i];
		move(next_x, next_y, cnt + deep[ny][nx]);
	}

	visited[ny][nx] = false;
}

void print_map() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << deep[y][x] << " ";
		}
		cout << endl;
	}
}

void solve() {
	inFile.getline(inputString, STRING_SIZE);

	T = stoi(inputString);

	for (int t = 1; t <= T; t++) {
		input();
		min_deep = first_check();
		//print_map();
		move(0, 0, 0);
		cout << "#" << t << " " << min_deep << endl;
	}

	inFile.close();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}