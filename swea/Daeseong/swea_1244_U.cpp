#include <iostream>
#include <string>
#include <queue>

#define N_MAX 6
#define M_MAX 10

using namespace std;

string given_num;
string max_str[M_MAX + 1];
int given_cnt;
int N;

void input() {
	cin >> given_num >> given_cnt;
	N = given_num.length();

	for (int i = 0; i <= given_cnt; i++) {
		max_str[i] = "0";
	}
}
string change(string str, int i, int j) {
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;

	return str;
}
void solution(string answer, int cnt) {
	if (cnt > given_cnt) return;
	if (answer < max_str[cnt]) return;


	max_str[cnt] = answer;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			solution(change(answer, i, j), cnt + 1);
		}
	}
}

void solve() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		input();
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				solution(change(given_num, i, j), 1);
			}
		}
		cout << "#" << tc << " " << max_str[given_cnt] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}