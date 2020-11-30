//Solution
//- 주어진 판에 대한 정보를 일일히 저장해야 되므로 구현에 많은 시간이 소요됨.
//- 다음에 유의하자.
//- 1. 중앙에서 이동할 때, 40에 도착하는 여부를 판단해야 함. 
//- 1.1. 본인의 경우 40에 도착하지 않고 도착지로 이동해 실패함.
//- 2. 시작점, 끝점은 유일하게 중복으로 말이 위치할 수 있는 지점임.
//- 2.1. 예제 4번의 경우, 말을 도착지로 빼내지 않으면 이동이 불가능한 상황이 발생한다.
//- 구현은 다음과 같다.
//- 1. 초기값을 세팅한다.
//- 1.1. turn에는 주사위 정보를 담는다.
//- 1.2. stone에는 돌의 위치를 담는다. 시작점은 0이다.
//- 1.3. map에는 말판의 정보를 담는다.
//- 1.3.1. 0은 시작점
//- 1.3.2. 1 ~ 20은 외곽
//- 1.3.3. 21 ~ 23은 중앙 좌측
//- 1.3.4. 24 ~ 25는 중앙 하단
//- 1.3.5. 26 ~ 28은 중앙 우측
//- 1.3.6. 29 ~ 31은 중앙 상단
//- 1.3.7. 32는 도착점
//- 2. dfs로 순회한다.
//- 2.1. 각각의 돌에 대해 다음을 수행한다.
//- 2.1.1. 도착지인 돌은 건드리지 않음.
//- 2.1.2. 5, 10, 15 위치의 돌은 지정된 경로로 주사위 값만큼 이동한다.
//- 2.1.3. 외곽 경로의 경우, 주사위 값만큼 이동한다.
//- 2.1.4. 안쪽 경로의 경우, 지정된 경로로 index를 변경하며 이동한다.
//- 2.2. 이동한 위치에서 다음을 확인한다.
//- 2.2.1. 내부에서 이동시 32는 40으로 표기된 위치이다. 
//- 2.2.2. 외곽에서 이동시 32는 도착지이다.
//- 2.2.3. 32이상의 모든 돌은 도착지이다.
//- 2.3. 각 돌의 위치에 해당하는 값을 더한 후 다음 dfs를 수행한다.
//- 3. 최대값을 update.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
vector<int> turn;
vector<int> stone;
vector<int> map;

void init() {
	int temp;
	for (int i = 0; i < 10; i++) {
		cin >> temp;
		turn.push_back(temp);
	}
	for (int i = 0; i < 4; i++) stone.push_back(0);

	map.push_back(0);										// 0 : start
	for (int i = 2; i <= 40; i += 2) map.push_back(i);		// 1 ~ 20
	for (int i = 13; i <= 19; i += 3) map.push_back(i);		// 21 ~ 23
	for (int i = 22; i <= 24; i += 2) map.push_back(i);		// 24 ~ 25
	for (int i = 28; i >= 26; i -= 1) map.push_back(i);		// 26 ~ 28
	for (int i = 25; i <= 35; i += 5) map.push_back(i);		// 29 ~ 31
	map.push_back(0);										// 32 : end
}

int move(int start, int move) {
	int end = start;
	if (end <= 20) {
		switch (end) {
		case 5:
			if (move <= 3) end = 20 + move;
			else end = 25 + move;
			break;
		case 10:
			if (move <= 2) end = 23 + move;
			else end = 26 + move;
			break;
		case 15:
			end = 25 + move;
			break;
		default:
			end += move;
			if (end > 20) end = 32;
		}
	}
	else if (end <= 23) {
		end += move;
		if (end >= 24) end = 29 + (end - 24);
		if (end == 32) end = 20;
	}
	else if (end <= 25) {
		end += move;
		if (end >= 26) end = 29 + (end - 26);
		if (end == 32) end = 20;
	}
	else {
		end += move;
		if (end == 32) end = 20;
	}

	if (end > 32) return 32;
	else return end;
}

void dfs(int t, int sum) {
	if (t >= 10) return;

	int before, next;
	for (int st = 0; st < 4; st++) {
		if (stone[st] == 32) continue;
		before = stone[st];
		next = move(stone[st], turn[t]);
		bool is_same = false;
		if (next == 32) {
			stone[st] = next;
			dfs(t + 1, sum);
			stone[st] = before;
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (st == i) continue;
				if (next == stone[i]) is_same = true;
			}
			if (is_same) continue;
			stone[st] = next;
			answer = max(answer, sum + map[next]);
			dfs(t + 1, sum + map[next]);
			stone[st] = before;
		}
	}
}

void solution() {
	init();
	dfs(0, 0);
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}