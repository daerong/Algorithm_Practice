// 골짜기를 찾는 문제로 시작위치가 0이다.
// 음수에서 0으로 변하는 지점의 갯수를 찾으면 쉽게 풀 수 있다.

#include <iostream>
#include <string>

using namespace std;

int result;
int N;
char *pattern;

void input() {
	cin >> N;
	pattern = new char[N];

	string str;
	cin >> str;
	for (int i = 0; i < N; i++) {
		pattern[i] = str[i];
	}
}

void hike() {
	int level = 0;

	for (int i = 0; i < N; i++) {
		switch (pattern[i]) {
		case 'U':
			level++;
			if (level == 0) result++;
			break;
		case 'D':
			level--;
			break;
		}
	}
}

void solve() {
	input();
	hike();

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}