// start : pm 3:53
// end : pm 4:12

// 38 이상의 수에 대해 5배수로 반올림 시행

#include <iostream>

using namespace std;

int N;
int *arr;

void input() {
	cin >> N;
	arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void print_final() {
	int diff;
	for (int i = 0; i < N; i++) {
		if (arr[i] < 38) {
			cout << arr[i] << endl;
			continue;
		}
		diff = arr[i] % 5;
		if (diff >= 3) arr[i] += 5 - diff;
		cout << arr[i] << endl;
	}
}

void solve(){
	input();
	print_final();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}