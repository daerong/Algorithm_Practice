// start : pm 6:06
// end : pm 6:15

// 가장 많은 숫자를 찾는 문제
// 빈도수가 같은 숫자 중 낮은 수를 리턴하면 되기때문에 판별식 잘 세우기

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