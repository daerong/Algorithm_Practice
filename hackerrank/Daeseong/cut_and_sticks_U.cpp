//Solution
//- If you arrange the sticks in ascending order, you can easily solve them.
//- When you use the priority queue, pop the sticks had same height.

#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

void input() {
	cin >> N;
	int temp;
	for (int n = 0; n < N; n++) {
		cin >> temp;
		pq.push(temp);
	}
}

void solve() {
	input();
	int cnt = N;
	cout << cnt << endl;

	int temp = pq.top();
	pq.pop();
	cnt--;

	while (!pq.empty()){
		if (temp != pq.top()) {
			cout << cnt << endl;
		}
		temp = pq.top();
		pq.pop();
		cnt--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}