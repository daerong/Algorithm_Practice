// start : pm 10:57
// translate : pm 11:14
// end : pm 11:48

// Solution
// 1. 가장 큰 수를 찾는다.
// 예외처리) 가장 큰 수는 자신의 번호보다 높은 위치에 있을 수 없다. (큰 수는 앞으로만 이동 가능하므로)
// 2. 가장 큰 수가 제 위치가 맞는 경우, 그 다음 큰 수를 찾는다.
// 3. 가장 큰 수가 제 위치가 아닌 경우, 바로 뒤 숫자와 위치를 바꾼다.
// 예외처리) 위치를 바꿀 수 있는 횟수는 2회


#include <iostream>

using namespace std;

#define N_MAX 100001

int T;
int N;
int arr[N_MAX];
int cost[N_MAX];

void show_arr() {
	for (int n = 1; n <= N; n++) {
		cout << arr[n] << " ";
	}

	cout << endl;
}

void arrange() {
	int last = N;
	int cnt = 0;
	int temp;
	for (int n = N; n >= 1; n--) {
		if (arr[n] != last) continue;		// 찾을 때 까지 이동
		if (arr[n] == n) {						// 제 위치
			last -= 1;
			continue;
		}
		if (n >= last) {					// 불가능한 조건, 큰수는 앞으로만 이동 가능
			cout << "Too chaotic" << endl;
			return;
		}

		if (cost[last] >= 2) {				// 불가능한 조건, 이동제한 2번
			cout << "Too chaotic" << endl;
			return;
		}

		temp = arr[n];
		arr[n] = arr[n + 1];
		arr[n + 1] = temp;
		cnt += 1;
		cost[last] += 1;

		n += 2;			// 한칸 앞이기 때문

		//show_arr();
	}

	cout << cnt << endl;
}

void solve() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;

		for (int n = 1; n <= N; n++) {
			cin >> arr[n];
			cost[n] = 0;
		}
		arrange();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}