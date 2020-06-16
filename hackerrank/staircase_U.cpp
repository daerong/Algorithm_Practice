// start : 10:03
// end :10:24

// '#'을 반복하면 실패
// str로 문자열을 만들어 출력하면 성공 .. 

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int N;

void input() {
	cin >> N;
}

void solution() {
	string str = "";
	for (int i = 0; i < N; i++) {
		str += '#';
		cout << setfill(' ') << setw(N) << str << endl;
	}
}

void solve() {
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();
	return 0;
}