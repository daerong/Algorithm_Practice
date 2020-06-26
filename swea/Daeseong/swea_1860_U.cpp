// start : pm 12:23
// end : pm 12:51

// Solution
// Using priority queue because client array is unsorted.
// But priority queue can't clear therefore doesn't decleard global var.

#include <iostream>
#include <queue>

using namespace std;

int T;		// result vol

void lets_cooking(priority_queue<int, vector<int>, greater<int>> pq, int t, int M, int K) {
	int time;
	int prev_client = 0;
	int order = 0;
	int cooked;
	while (!pq.empty()) {
		time = pq.top();
		pq.pop();
		order++;
		cooked = (time / M) * K;			// 연산순서

		if (cooked - order < 0) {
			cout << "#" << t << " Impossible" << endl;
			return;
		}
	}
	
	cout << "#" << t << " Possible" << endl;
}

void solution() {
	cin >> T;

	int N;		// client vol
	int M;		// cooking time
	int K;		// cooking how many
	int temp;
	for (int t = 0; t < T; t++) {
		cin >> N >> M >> K;

		priority_queue<int, vector<int>, greater<int>> pq;
		for (int n = 0; n < N; n++) {
			cin >> temp;
			pq.push(temp);
		}

		lets_cooking(pq, t + 1, M, K);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
