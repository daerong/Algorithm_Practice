// start : pm 11:52
// translation : am 12:03
// end : am 12:07

#include <iostream>

using namespace std;
int N;
int M;
int S;

void input() {
	cin >> N >> M >> S;
}

int solution() {
	int result = (M + (S - 1)) % N;
	if (result) return result;
	else return N;
}

void solve() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		input();
		cout << solution() << endl;;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}