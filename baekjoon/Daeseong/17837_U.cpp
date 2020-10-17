//Solution
//- �������� ��, �ൿ�� ���� ����� �����ϸ� ���� Ǯ �� �ִ�.
//- Failed 1 : STONE map[y][x] ���� ����� ���ÿ����� ��밡��, ���α׷��ӽ������� ���Ұ��ϴ� 2���� ���� ���.
//- Failed 2 : �̵��ϴ� �� �ؿ� �ִ� ���� �������� �ʴ´�.
//- Ǯ�̰����� ������ ����.
//- 1. �Է°����� �⺻ ���� �����Ѵ�.
//- 1.1. vector<vector<MAP>> map���� color ������ ��´�.
//- 1.2. �� ������ vector<STONE> stones�� ��´�.
//- 2. 1���� 1000������ turn�� ���� ������ �ݺ��Ѵ�.
//- 2.1. ��� ���� ���� move()�� �����Ѵ�.
//- 2.1.1. �̵��� ��ġ�� ���� ���, ������ �ٲ� �� ���� �̵� ��ġ�� ���� ������ �����Ѵ�.
//- 2.1.1.1. �̵��� ��ġ�� �Ķ��� ���, �����.
//- 2.1.1.2. �� ���� ���, 2.1.3.�̳� 2.1.4.�� �����Ѵ�.
//- 2.1.2. �̵��� ��ġ�� �Ķ��� ���, ������ �ٲ� �� ���� �̵� ��ġ�� ���� ������ �����Ѵ�.
//- 2.1.2.1. �̵��� ��ġ�� ���� ���, �����.
//- 2.1.2.2. �̵��� ��ġ�� �Ķ��� ���, �����.
//- 2.1.2.3. �� ���� ���, 2.1.3.�̳� 2.1.4.�� �����Ѵ�.
//- 2.1.3. �̵��� ��ġ�� ����� ���, �̵��� ��ġ�� �״�� ��´�.
//- 2.1.4. �̵��� ��ġ�� ������ ���, �̵��� ��ġ�� �������� ��´�.
//- 2.1.5. �̵��� ��ġ�� ���� 4�� �̻��� ��� ���� �� ������ return�Ѵ�.
//- 2.1.6. 2.1.�� ���ư� �ݺ��Ѵ�.
//- 2.2. 1000������ ��� 2.�� �ݺ��Ѵ�.
//- 3. 1000�� ���� ��, ������� �����Ƿ� -1�� return�Ѵ�.


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define N_MAX 12
typedef struct STONE {
	int x;
	int y;
	int dir;
} STONE;

typedef struct MAP {
	int color;			// red 1, blue 2
	vector<int> vec;
};

vector<STONE> stones;
vector<vector<MAP>> map;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N;		// map size
int K;

bool move(int target_id) {
	int x = stones[target_id].x;
	int y = stones[target_id].y;
	int dir = stones[target_id].dir;
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
		if (dir % 2) stones[target_id].dir -= 1;
		else stones[target_id].dir += 1;
		dir = stones[target_id].dir;
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (map[ny][nx].color == 2) return false;
	}
	else if (map[ny][nx].color == 2) {
		if (dir % 2) stones[target_id].dir -= 1;
		else stones[target_id].dir += 1;
		dir = stones[target_id].dir;
		nx = x + dx[dir];
		ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) return false;
		if (map[ny][nx].color == 2) return false;
	}
	if (map[ny][nx].color == 0) {
		int find_id = -1;
		bool finded = false;
		for (int target = 0; target < map[y][x].vec.size(); target++) {
			if (target_id == map[y][x].vec[target]) {
				finded = true;
				find_id = target;
			}
			if (finded) {
				map[ny][nx].vec.push_back(map[y][x].vec[target]);
				stones[map[y][x].vec[target]].x = nx;
				stones[map[y][x].vec[target]].y = ny;
			}
		}
		map[y][x].vec.erase(map[y][x].vec.begin() + find_id, map[y][x].vec.end());
	}
	else if (map[ny][nx].color == 1) {
		int find_id = -1;

		for (int target = map[y][x].vec.size() - 1; target >= 0; target--) {
			if (target_id == map[y][x].vec[target]) {
				map[ny][nx].vec.push_back(map[y][x].vec[target]);
				stones[map[y][x].vec[target]].x = nx;
				stones[map[y][x].vec[target]].y = ny;
				find_id = target;
				break;
			}
			else {
				map[ny][nx].vec.push_back(map[y][x].vec[target]);
				stones[map[y][x].vec[target]].x = nx;
				stones[map[y][x].vec[target]].y = ny;
			}
		}

		map[y][x].vec.erase(map[y][x].vec.begin() + find_id, map[y][x].vec.end());
	}

	if (map[ny][nx].vec.size() >= 4) return true;
	else return false;
}


int solution() {
	for (int turn = 1; turn <= 1000; turn++) {
		for (int k = 1; k < stones.size(); k++) {
			if (move(k)) return turn;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int y = 0; y < N; y++) {
		vector<MAP> line;
		for (int x = 0; x < N; x++) {
			MAP temp;
			cin >> temp.color;
			line.push_back(temp);
		}
		map.push_back(line);
	}

	stones.push_back({ -1, -1, -1 });		// 0 �����ϰ� ���

	int x, y, dir;
	for (int i = 1; i <= K; i++) {
		cin >> y >> x >> dir;
		map[y - 1][x - 1].vec.push_back(i);
		stones.push_back({ x - 1, y - 1, dir - 1 });
	}

	cout << solution() << endl;

	return 0;
}