//Solution
//- �迭�� ���� ��ġ�� ���Ƿ� �����ϱ� ���� �ε����� ��� �ٲ���ϴ� ����.
//- �̷��� ������ ������ ����.
//- 1. �����̾� ��Ʈ�� 0��° ��ġ�� '���� ��ġ'�� �Ѵ�.
//- 2. �����̾� ��Ʈ�� N-1��° ��ġ�� '�� ��ġ'�� �Ѵ�.
//- 3. �����̾� ��Ʈ�� �̵��� �� '���� ��ġ'�� '�� ��ġ'�� 1�� �����Ѵ�.
//- 3.1. ��, ��� �ϳ��� ��ġ�� 0���� ���� ��쿡�� N * 2�� ���� ��ġ�� �����Ѵ�.
//- 4. �����̾� ��Ʈ ���� �κ��� ���� ���, '�� ��ġ'���� ����� ������� ������ �����Ѵ�.
//- 4.1. �κ��� '�� ��ġ'�� �ִٸ� ������.
//- 4.2. �κ��� �� ��ġ�� ����ִٸ� �̵��Ѵ�.
//= 4.2.1. ��, �� ��ġ�� �������� 0�̶�� �̵��� �� ����.
//- 4.2.2. �̵��� ���Ŀ��� ��Ʈ ��ġ�� �������� 1 ���ҽ�Ų��.
//- 4.2.3. �̵� ���Ŀ� �������� 0�� �ȴٸ� K�� 1���ҽý�Ų��.
//- 5. '���� ��ġ'�� ����ִٸ� �ش� ��ġ�� �κ��� ��ġ��Ų��.
//- 5.1. ��, '���� ��ġ'�� �������� 0�̶�� �̵��� �� ����.
//- 5.2. �̵��� ���Ŀ��� ��Ʈ ��ġ�� �������� 1 ���ҽ�Ų��.
//- 5.3. �̵� ���Ŀ� �������� 0�� �ȴٸ� K�� 1���ҽý�Ų��.
//- 6. 3.~5.�� �ݺ��ϸ� K�� 0���� �۾����� ������ ã�� ���� Ƚ���� ����Ѵ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. struct STEP : {������, ����ִ� ����}
//- 1.2. map[] : STEP ����ü�� ����� �����̾� ��Ʈ
//- 1.3. s_locate : �κ��� �����̾� ��Ʈ�� �����ϴ� "���� ��ġ"
//- 1.4. e_locate : �κ��� �����̾� ��Ʈ�� ���������� "�� ��ġ"
//- 1.5. t : ���� Ƚ��, �ʱⰪ 0
//- 2. move()�� �ݺ��ϸ� K�� 0 ���ϰ� �Ǵ� ������ t ���� ã�´�.
//- 2.1. t�� 1 ������Ų��.
//- 2.2. s_locate�� 1 ���ҽ�Ų��.
//- 2.3. e_locate�� 1 ���ҽ�Ų��.
//- 2.4. s_locate�� e_locate�� 0���� �۾����� 2 * N - 1 ��ġ�� �����Ѵ�.
//- 2.5. e_locate ��ġ�� �κ��� ����. map[e_locate] = true
//- 2.6. e_locate ~ s_locate ������ ��� �κ��� ���� ������ �����Ѵ�. map[locate].is_empty == false
//- 2.6.1. map[locate + 1]�� ��ġ�� ����ִٸ� �̵��Ѵ�. 
//- 2.6.1.1. ��, locate + 1 = 2 * N - 1�� ���, ��ġ�� 0���� �Ѵ�.
//- 2.6.2. �̵��� ���, map[locate + 1].cnt�� 1 ���ҽ�Ų��.
//- 2.6.3. map[locate + 1].cnt == 0�� ���, K�� 1 ���ҽ�Ų��.
//- 2.7. e_locate ��ġ�� �κ��� ����.map[e_locate] = true
//- 2.8. s_locate ��ġ�� �κ��� �ִ´�. map[s_locate].is_empty == false
//- 2.8.1. ��, map[s_locate].cnt == 0�� ���, �����Ѵ�.
//- 2.8.2. �̵��� ���, map[s_locate].cnt�� 1 ���ҽ�Ų��.
//- 2.6.3. map[s_locate].cnt == 0�� ���, K�� 1 ���ҽ�Ų��.
//- 3. K�� 0 ���ϰ� �ƴٸ� t�� ����Ѵ�.

#include <iostream>

using namespace std;

#define N_MAX 201

typedef struct STEP {
	int cnt;
	bool is_empty;
} STEP;

int N;
int N2;
int K;
STEP map[N_MAX];
int s_locate;
int e_locate;

void init() {
	cin >> N >> K;
	N2 = 2 * N;
	int temp;
	for (int i = 0; i < 2 * N; i++) {
		cin >> temp;
		map[i] = { temp, true };
	}
	s_locate = 0;
	e_locate = N - 1;
}

void move() {
	if (s_locate == 0) s_locate = N2 - 1;
	else s_locate -= 1;
	if (e_locate == 0) e_locate = N2 - 1;
	else e_locate -= 1;

	map[e_locate].is_empty = true;

	int front;
	int back;
	for (int i = 0; i < N; i++) {
		front = e_locate - i;
		back = front - 1;
		if (front < 0) front += N2;
		if (back < 0) back += N2;
		if (!map[front].is_empty) continue;

		if (map[front].is_empty && !map[back].is_empty) {
			if (map[front].cnt > 0) {
				map[front].is_empty = false;
				map[back].is_empty = true;
				map[front].cnt -= 1;
				if (map[front].cnt == 0) K--;
			}
		}
	}

	map[e_locate].is_empty = true;

	if (map[s_locate].is_empty) {
		if (map[s_locate].cnt > 0) {
			map[s_locate].is_empty = false;
			map[s_locate].cnt -= 1;
			if (map[s_locate].cnt == 0) K--;
		}
	}
}

//void print_map() {
//	for (int i = 0; i < N2; i++) {
//		cout << map[(s_locate + i) % N2].cnt << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i < N2; i++) {
//		if (map[(s_locate + i) % N2].is_empty) cout << "X ";
//		else  cout << "O ";
//	}
//	cout << endl;
//	cout << endl;
//}

void solution() {
	init();
	int t = 0;
	while (K > 0) {
		t++;
		move();
		//print_map();
	}

	cout << t << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}