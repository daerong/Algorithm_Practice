//Solution
//- �־��� �ǿ� ���� ������ ������ �����ؾ� �ǹǷ� ������ ���� �ð��� �ҿ��.
//- ������ ��������.
//- 1. �߾ӿ��� �̵��� ��, 40�� �����ϴ� ���θ� �Ǵ��ؾ� ��. 
//- 1.1. ������ ��� 40�� �������� �ʰ� �������� �̵��� ������.
//- 2. ������, ������ �����ϰ� �ߺ����� ���� ��ġ�� �� �ִ� ������.
//- 2.1. ���� 4���� ���, ���� �������� ������ ������ �̵��� �Ұ����� ��Ȳ�� �߻��Ѵ�.
//- ������ ������ ����.
//- 1. �ʱⰪ�� �����Ѵ�.
//- 1.1. turn���� �ֻ��� ������ ��´�.
//- 1.2. stone���� ���� ��ġ�� ��´�. �������� 0�̴�.
//- 1.3. map���� ������ ������ ��´�.
//- 1.3.1. 0�� ������
//- 1.3.2. 1 ~ 20�� �ܰ�
//- 1.3.3. 21 ~ 23�� �߾� ����
//- 1.3.4. 24 ~ 25�� �߾� �ϴ�
//- 1.3.5. 26 ~ 28�� �߾� ����
//- 1.3.6. 29 ~ 31�� �߾� ���
//- 1.3.7. 32�� ������
//- 2. dfs�� ��ȸ�Ѵ�.
//- 2.1. ������ ���� ���� ������ �����Ѵ�.
//- 2.1.1. �������� ���� �ǵ帮�� ����.
//- 2.1.2. 5, 10, 15 ��ġ�� ���� ������ ��η� �ֻ��� ����ŭ �̵��Ѵ�.
//- 2.1.3. �ܰ� ����� ���, �ֻ��� ����ŭ �̵��Ѵ�.
//- 2.1.4. ���� ����� ���, ������ ��η� index�� �����ϸ� �̵��Ѵ�.
//- 2.2. �̵��� ��ġ���� ������ Ȯ���Ѵ�.
//- 2.2.1. ���ο��� �̵��� 32�� 40���� ǥ��� ��ġ�̴�. 
//- 2.2.2. �ܰ����� �̵��� 32�� �������̴�.
//- 2.2.3. 32�̻��� ��� ���� �������̴�.
//- 2.3. �� ���� ��ġ�� �ش��ϴ� ���� ���� �� ���� dfs�� �����Ѵ�.
//- 3. �ִ밪�� update.

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