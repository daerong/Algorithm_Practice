#include <iostream>
#define N_MAX 50
using namespace std;

int liked[N_MAX + 1];
int cumulative[N_MAX + 1];
int shared = 5;
int N;

void input() {
	for (int i = 1; i <= N_MAX; i++) {
		liked[i] = shared / 2;
		cumulative[i] = cumulative[i - 1] + liked[i];
		shared = liked[i] * 3;
	}

	cin >> N;
}
void solve() {
	input();
	cout << cumulative[N];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	
	return 0;
}