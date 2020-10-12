#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define endl '\n'
#define N_MAX 10 + 1

typedef struct TREE {
	int x;
	int y;
	int year;
} TREE;

bool compare(TREE a, TREE b) {
	return a.year < b.year;
}

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int N;		// 맵 크기
int M;		// 나무 수
int K;		// term
int soil[N_MAX][N_MAX];
int A[N_MAX][N_MAX];

queue<TREE> spring(vector<TREE>& trees) {
	queue<TREE> dead_tree;

	for (vector<TREE>::iterator iter = trees.begin(); iter != trees.end(); ) {
		if (soil[(*iter).x][(*iter).y] >= (*iter).year) {
			soil[(*iter).x][(*iter).y] -= (*iter).year;
			(*iter).year += 1;

			iter++;
		}
		else {
			dead_tree.push(*iter);
			iter = trees.erase(iter);
		}
	}

	return dead_tree;
}

void summer(queue<TREE> dead_tree) {
	TREE temp;
	while (!dead_tree.empty()) {
		temp = dead_tree.front();
		dead_tree.pop();

		soil[temp.x][temp.y] += temp.year / 2;
	}
}

void fall(vector<TREE>& trees) {
	int tree_vol = trees.size();
	for (int i = 0; i < tree_vol; i++) {
		if (trees[i].year % 5 == 0) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = trees[i].x + dx[dir];
				int ny = trees[i].y + dy[dir];
				if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
				trees.push_back({ nx, ny, 1 });
			}
		}
	}
}

void winter() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			soil[r][c] += A[r][c];
		}
	}
}

int solution(vector<TREE> trees, int K) {
	for (int k = 1; k <= K; k++) {
		summer(spring(trees));
		fall(trees);
		winter();
	}

	return trees.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<TREE> trees;

	cin >> N >> M >> K;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> A[r][c];
			soil[r][c] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		trees.push_back({ x, y, z });
	}

	cout << solution(trees, K);

	return 0;
}