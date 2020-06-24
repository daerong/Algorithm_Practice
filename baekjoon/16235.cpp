#include <iostream>
#include <algorithm>

using namespace std;

int result;
int N;
int **matrix;

void input() {
	cin >> N;
	matrix = new int*[N];
	for (int y = 0; y < N; y++) {
		matrix[y] = new int[N];
		for(int x = 0; x < N; x++){
			cin >> matrix[y][x];
		}
	}
}

void solution() {
	int upperSum = 0;
	int lowerSum = 0;
	for (int i = 0; i < N; i++) {
		upperSum += matrix[i][N - 1 - i];
		lowerSum += matrix[i][i];
	}

	result = abs(upperSum - lowerSum);
}

void solve() {
	input();
	solution();
	cout << result;
}

int main() {
	solve();
	return 0;
}