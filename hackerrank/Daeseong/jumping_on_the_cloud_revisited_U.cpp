//Solution
//- Using DFS algorithm.

#include <iostream>

using namespace std;

#define N_MAX 25

int N;
int K;
bool clouds[N_MAX];
bool visited[N_MAX];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> clouds[i];
	}
}

int jump(int target, int sum) {
	if (visited[target]) {
		return sum;
	}
	
	visited[target] = true;

	int next = target + K;
	if (next >= N) next -= N;

	if(clouds[next]) return jump(next, sum - 3);
	else return jump(next, sum - 1);
}

void solve() {
	input();
	cout << jump(0, 100);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}