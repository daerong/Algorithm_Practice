//Solution
//- �־��� �������� ���� �� �ִ� ��� ���ڿ��� ����ϴ� ����.
//- �ùķ��̼�, DFS, ��Ʈ��ŷ
//- �̷��� ������ ������ ����.
//- 1. �־��� ���ڹ迭�� ������������ �����Ѵ�.
//- 2. DFS�� ��ȸ�ϸ鼭 ������ ������ ã�´�.
//- 2.1. ���̰� 4�̸鼭, 
//- 2.2. ������ 1�� �̻�
//- 2.3. ������ 2�� �̻�
//- 3. ���� ���� ��� ���ڿ��� ã�� �� �ִ�.
//- Ǯ�� ����� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. L : ���� ���ڿ��� ����
//- 1.2. C : �־��� ������ ����
//- 1.3. arr : �־��� ���� �迭
//- 1.4. result : ��� ���ڿ� �迭
//- 1.5. s : ������ ����� set
//- 2. dfs()�Լ��� ����� ���ǿ� �´� ���ڿ��� ã�´�.
//- 2.1. cnt == L�� ���ڿ��� ���� ������ Ȯ���Ѵ�. (cnt�� str�� ����)
//- 2.1.1. ������ 1�� �̻��̰� ������ 2�� �̻��� �����̸� ������ �����Ѵ�.
//- 2.1.2. result �迭�� str�� �ִ´�.
//- 2.2. dfs()�� index�� �̵���Ű�� ����ó�� Ȯ���Ѵ�.
//- 2.2.1. ���� ���ڸ� �����ϴ� ���, 
//- 2.2.1.1. ���繮�ڰ� �����̸� cnt���� s_cnt ���� 1������Ų �� �̵��Ѵ�.
//- 2.2.1.2. ���繮�ڰ� �����̸� cnt���� 1������Ų �� �̵��Ѵ�.
//- 2.2.2. ���� ���ڸ� �������� �ʴ� ���,
//- 2.2.2.1. index�� �̵��Ͽ� �����Ѵ�.
//- 2.3. ������ ��� ���, �����Ѵ�.
//- 3. 2.������ ���� ������ ��� ���ڿ��� ����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

vector<char> arr;
int L;
int C;
unordered_set<char> s;
set<string> result;

void init() {
	cin >> L >> C;
	char temp;
	for (int c = 0; c < C; c++) {
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');
}

void dfs(int target, int cnt, string str, int s_cnt) {
	if (cnt == L) {
		if (s_cnt >= 1 && cnt - s_cnt >= 2) {
			result.insert(str);
		}
		return;
	}
	if (target >= C) return;

	if (s.count(arr[target]) == 1) dfs(target + 1, cnt + 1, str + arr[target], s_cnt + 1);
	else dfs(target + 1, cnt + 1, str + arr[target], s_cnt);
	dfs(target + 1, cnt, str, s_cnt);
}

void solution() {
	init();
	dfs(0, 0, "", 0);
	for (set<string>::iterator it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie();

	solution();

	return 0;
}