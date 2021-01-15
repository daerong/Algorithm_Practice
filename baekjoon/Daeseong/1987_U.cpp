//Solution
//- ���ĺ� �ߺ� ���� ���� ��� ������ �� �ִ� path�� ã�� ����
//- �̷��� ������ ������ ����.
//- 1. dfs�� �����ϸ鼭 �����θ� ã�� �� �ִ�.
//- 2. ���ĺ��� 26�ڷ� 26���� ��Ʈ�� �湮���θ� üũ�� �� �ִ�.
//- 3. �̵��ϸ鼭 �湮���θ� üũ�ϰ� Ȯ���Ѵ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. dx[], dy[] : ������ ���� �̵��ϱ� ���� ����
//- 1.2. char[][] map : �־��� ���ĺ� �迭
//- 1.3. answer : ������ �� �ִ� �ִ����
//- 2. dfs() �Լ��� ���� ������̸� Ȯ���Ѵ�.
//- 2.1. ������ ��� ��ġ�� ���� ������ �����Ѵ�.
//- 2.1.1. answer < cnt�� ���, answer�� cnt�� �����Ѵ�.
//- 2.2. �� �湮�� üũ�Ѵ�.
//- 2.2.1. checked & 1 << ���ĺ� �ѹ�(A = 0, B = 1 ...)�� Ȯ���� �� �ִ�.
//- 2.2.2. �� �湮 ��, 
//- 2.2.2.1. answer < cnt�� ���, answer�� cnt�� �����Ѵ�.
//- 2.3. ������ ���⿡ ���� dfs()�� �����Ѵ�.
//- 3. answer�� ����Ѵ�.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 20

int Y;
int X;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
vector<string> map;
int answer;

void init() {
	cin >> Y >> X;
	string temp;
	for (int y = 0; y < Y; y++) {
		cin >> temp;
		map.push_back(temp);
	}
}

int get_index(char target) {
	return target - 'A';
}

void dfs(int x, int y, int checked, int cnt) {
	if (x < 0 || x >= X || y < 0 || y >= Y) {
		answer = max(answer, cnt);
		return;
	}
	if (checked & (1 << get_index(map[y][x]))) {
		answer = max(answer, cnt);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		dfs(nx, ny, checked | (1 << get_index(map[y][x])), cnt + 1);
	}
}

void solution() {
	init();
	dfs(0, 0, 0, 0);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}