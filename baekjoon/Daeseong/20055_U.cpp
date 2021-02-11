//Solution
//- 배열의 시작 위치를 임의로 변경하기 위해 인덱스를 계속 바꿔야하는 문제.
//- 이론적 접근은 다음과 같다.
//- 1. 컨베이어 벨트의 0번째 위치를 '시작 위치'라 한다.
//- 2. 컨베이어 벨트의 N-1번째 위치를 '끝 위치'라 한다.
//- 3. 컨베이어 벨트가 이동할 때 '시작 위치'와 '끝 위치'는 1씩 감소한다.
//- 3.1. 단, 어느 하나의 위치라도 0보다 작을 경우에는 N * 2를 더한 위치로 정정한다.
//- 4. 컨베이어 벨트 위에 로봇이 있을 경우, '끝 위치'에서 가까운 순서대로 다음을 수행한다.
//- 4.1. 로봇이 '끝 위치'에 있다면 내린다.
//- 4.2. 로봇의 앞 위치가 비어있다면 이동한다.
//= 4.2.1. 단, 앞 위치의 내구도가 0이라면 이동할 수 없다.
//- 4.2.2. 이동한 이후에는 벨트 위치의 내구도를 1 감소시킨다.
//- 4.2.3. 이동 이후에 내구도가 0이 된다면 K를 1감소시시킨다.
//- 5. '시작 위치'가 비어있다면 해당 위치에 로봇을 위치시킨다.
//- 5.1. 단, '시작 위치'의 내구도가 0이라면 이동할 수 없다.
//- 5.2. 이동한 이후에는 벨트 위치의 내구도를 1 감소시킨다.
//- 5.3. 이동 이후에 내구도가 0이 된다면 K를 1감소시시킨다.
//- 6. 3.~5.를 반복하며 K가 0보다 작아지는 순간을 찾아 수행 횟수를 출력한다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 선언한다.
//- 1.1. struct STEP : {내구도, 비어있는 여부}
//- 1.2. map[] : STEP 구조체로 선언된 컨베이어 벨트
//- 1.3. s_locate : 로봇이 컨베이어 벨트에 진입하는 "시작 위치"
//- 1.4. e_locate : 로봇이 컨베이어 벨트를 삐져나오는 "끝 위치"
//- 1.5. t : 수행 횟수, 초기값 0
//- 2. move()를 반복하며 K가 0 이하가 되는 순간의 t 값을 찾는다.
//- 2.1. t를 1 증가시킨다.
//- 2.2. s_locate를 1 감소시킨다.
//- 2.3. e_locate를 1 감소시킨다.
//- 2.4. s_locate나 e_locate가 0보다 작아지면 2 * N - 1 위치를 지정한다.
//- 2.5. e_locate 위치의 로봇을 뺀다. map[e_locate] = true
//- 2.6. e_locate ~ s_locate 구간의 모든 로봇에 대해 다음을 수행한다. map[locate].is_empty == false
//- 2.6.1. map[locate + 1]의 위치가 비어있다면 이동한다. 
//- 2.6.1.1. 단, locate + 1 = 2 * N - 1인 경우, 위치를 0으로 한다.
//- 2.6.2. 이동한 경우, map[locate + 1].cnt를 1 감소시킨다.
//- 2.6.3. map[locate + 1].cnt == 0인 경우, K를 1 감소시킨다.
//- 2.7. e_locate 위치의 로봇을 뺀다.map[e_locate] = true
//- 2.8. s_locate 위치에 로봇을 넣는다. map[s_locate].is_empty == false
//- 2.8.1. 단, map[s_locate].cnt == 0인 경우, 무시한다.
//- 2.8.2. 이동한 경우, map[s_locate].cnt를 1 감소시킨다.
//- 2.6.3. map[s_locate].cnt == 0인 경우, K를 1 감소시킨다.
//- 3. K가 0 이하가 됐다면 t를 출력한다.

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