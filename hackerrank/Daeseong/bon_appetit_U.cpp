// start : am 00:26
// end : am 00:40

// 예외처리만 잘하면 되는 문제

#include <iostream>

using namespace std;

int result;
int N;
int k;
int anna;
int brian;

void input() {
	cin >> N >> k;
	int sum = 0;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (i != k) sum += temp;
	}
	cin >> brian;
	anna = sum / 2;
}

void solve() {
	input();

	result = brian - anna;

	if(result > 0) cout << result;
	else cout << "Bon Appetit";
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}