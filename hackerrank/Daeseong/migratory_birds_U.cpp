// start : pm 6:06
// end : pm 6:15

// ���� ���� ���ڸ� ã�� ����
// �󵵼��� ���� ���� �� ���� ���� �����ϸ� �Ǳ⶧���� �Ǻ��� �� �����

#include <iostream>
#include <algorithm>

using namespace std;

int result;
int num[6];

int N;
int *arr;

void input() {
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int cnt() {
	for (int i = 0; i < N; i++) {
		num[arr[i]] += 1;
	}

	int max = 0;
	int max_num;
	for (int n = 1; n < 6; n++) {
		if (max < num[n]) {
			max_num = n;
			max = num[n];
		}
	}

	return max_num;
}

void solve() {
	input();
	result = cnt();
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}