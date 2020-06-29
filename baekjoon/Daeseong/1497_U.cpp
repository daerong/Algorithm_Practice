// 모든 m에 대해 연주할 필요 x
// 가능한 최대 m에 대한 n을 구하는 문제

// m의 최대값과 n의 최소값을 변화시키며 DFS로 순회


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N_MAX 10

int result = 11;
int N;
int M;
string board[N_MAX];

int m_limit;

void input() {
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		cin >> board[n] >> board[n];
	}
}

void solution(int n_now, bool* visited_n, string str, int n_cnt) {
	if (n_cnt >= result) return;

	visited_n[n_now] = true;
	for (int m = 0; m < M; m++) {
		if (str[m] == 'Y') continue;
		if (board[n_now][m] == 'N') continue;
		str[m] = board[n_now][m];
	}
	
	for (int n = n_now + 1; n < N; n++) {
		solution(n, visited_n, str, n_cnt + 1);
	}

	int cnt = 0;
	for (int m = 0; m < M; m++) {
		if (str[m] == 'Y') cnt++;
	}

	if (cnt == 0) {
		visited_n[n_now] = false;
		return;
	}

	if (cnt > m_limit) {
		result = n_cnt;
		m_limit = cnt;
	}
	else if (cnt == m_limit) {
		result = min(result, n_cnt);
	}

	visited_n[n_now] = false;
}

void solve() {
	input();

	bool visited_n[N_MAX] = { false, };
	string str;
	for (int n = 0; n < N; n++) {
		str = board[n];
		solution(n, visited_n, str, 1);
	}

	if (result == 11) cout << -1;
	else cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}