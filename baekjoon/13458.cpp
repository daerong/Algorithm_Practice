#include <iostream>

using namespace std;

long long result = 0;

int N = 0;			// 시험장 갯수
int man[1000001];	// 응시자 수
int B = 0;			// 주감독관 커버량
int C = 0;			// 부감독관 커버량

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> man[i];
	}
	cin >> B;
	cin >> C;
}

void solution() {
	for (int i = 0; i < N; i++) {
		int mans = man[i] - B;
		if (mans <= 0) result += 1;
		else {
			int C_cnt = mans / C;
			if (mans - C_cnt * C == 0) result += C_cnt + 1;		// 딱 떨어짐
			else result += C_cnt + 2;
		}
	}
}

void solve() {
	input();
	solution();
	cout << result;
}

int main() {
	solve();
	return 0;
}