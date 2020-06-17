// int가 페어인 경우 1이 증가
// 정렬된 배열에서 1번의 순회로 결과를 구할 수 있음
// priority queue 사용

#include <iostream>
#include <queue>

using namespace std;

int result;
int N;				// the number of sock.
priority_queue<int> sock_queue;

void input() {
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sock_queue.push(temp);
	}
}

void match_pair() {
	int temp = -1;
	while (!sock_queue.empty()) {
		if (temp != sock_queue.top()) {
			// diffrent with before sock
			temp = sock_queue.top();
		}
		else {
			result++;
			temp = -1;
		}

		sock_queue.pop();
	}
}

void solve() {
	input();
	match_pair();
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}