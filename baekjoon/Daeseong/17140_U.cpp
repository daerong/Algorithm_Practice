//Solution
//- �̻��� ������ �����ϴ� ����, �迭�� ũ�⿡ ������� Ư����ġ�� ������ ���� Ȯ���ϸ� �ȴ�.
//- Ǯ�̰����� ������ ����.
//- 1. �־��� 3x3 ���� map[y][x]�� ��´�.
//- 2. �־��� ��ġ�� ���ڸ� Ȯ���Ͽ� map[r][c] == k�̸� ����Ƚ���� �����Ѵ�.
//- 3. ���� ũ�� X�� ���� ũ�� Y�� ���Ͽ� ������ �����Ѵ�.
//- 3.1. Y >= X�� ���, ������ �����Ѵ�.
//- 3.1.1. �� �࿡ ���� 1 ~ 100���� ���� ������ ������ num[] �迭�� ��´�.
//- 3.1.2. �� ���� �����ϱ� ���� {����, ����} ���� vec(������ ������, ������ ������ ����)�� ��´�.
//- 3.1.3. vec���� ���Ҹ� ���� �� �ΰ��� �ʿ� �߰��Ѵ�. ����, ���� ����
//- 3.1.4. �� �࿡ ���� 2.1.3.���� �߰��� �ִ� ������ X�� ������Ʈ�Ѵ�.
//- 3.2. Y < X�� ���, ������ �����Ѵ�.
//- 3.2.1. �� ���� ���� 1 ~ 100���� ���� ������ ������ num[] �迭�� ��´�.
//- 3.2.2. �� ���� �����ϱ� ���� {����, ����} ���� vec(������ ������, ������ ������ ����)�� ��´�.
//- 3.2.3. vec���� ���Ҹ� ���� �� �ΰ��� �ʿ� �߰��Ѵ�. ����, ���� ����
//- 3.2.4. �� ���� ���� 2.1.3.���� �߰��� �ִ� ������ Y�� ������Ʈ�Ѵ�.
//- 3.3. 2.�� ���ư� �ٽ� Ȯ���Ѵ�.
//- 4. 100������ ���� ��, ����� ���� ���ϸ� -1�� �����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAP_MAX 100

typedef struct UDS {
	int num;
	int vol;
} UDS;
bool compare(UDS a, UDS b) {
	if (a.vol == b.vol) return a.num < b.num;
	else return a.vol < b.vol;
}

int r;		// y
int c;		// x
int k;
int Y;		// y max
int X;		// x max

int map[MAP_MAX][MAP_MAX];
int num[MAP_MAX + 1];
vector<UDS> vec;

void reset_num() {
	for (int i = 1; i <= MAP_MAX; i++) num[i] = 0;
}

//void print_map() {
//	for (int y = 0; y < Y; y++) {
//		for (int x = 0; x < X; x++) {
//			cout << map[y][x] << " ";
//		}
//
//		cout << endl;
//	}
//}

int solution() {
	for (int t = 0; t <= 100; t++) {
		if (map[r][c] == k) return t;

		if (Y >= X) {
			int new_X = 0;
			for (int y = 0; y < Y; y++) {
				reset_num();
				for (int x = 0; x < X; x++) {
					num[map[y][x]] += 1;
					map[y][x] = 0;
				}

				for (int i = MAP_MAX; i > 0; i--) {
					if (num[i] == 0) continue;
					vec.push_back({ i, num[i] });
				}
				sort(vec.begin(), vec.end(), compare);

				int index = 0;
				for (int i = 0; i < vec.size(); i++) {
					if (index >= MAP_MAX) break;
					map[y][index++] = vec[i].num;
					map[y][index++] = vec[i].vol;
				}

				vec.clear();
				if (new_X < index) new_X = index;
			}
			X = new_X;
		}
		else {
			int new_Y = 0;
			for (int x = 0; x < X; x++) {
				reset_num();
				for (int y = 0; y < Y; y++) {
					num[map[y][x]] += 1;
					map[y][x] = 0;
				}

				for (int i = MAP_MAX; i > 0; i--) {
					if (num[i] == 0) continue;
					vec.push_back({ i, num[i] });
				}
				sort(vec.begin(), vec.end(), compare);

				int index = 0;
				for (int i = 0; i < vec.size(); i++) {
					if (index >= MAP_MAX) break;
					map[index++][x] = vec[i].num;
					map[index++][x] = vec[i].vol;
				}

				vec.clear();
				if (new_Y < index) new_Y = index;
			}
			Y = new_Y;
		}

		//print_map();
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	r -= 1;	c -= 1;
	Y = 3;	X = 3;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> map[y][x];
		}
	}

	cout << solution() << endl;

	return 0;
}