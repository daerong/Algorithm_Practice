//Solution
//- Count number with the largest number and print the diffrence the size of array between it.

#include <iostream>

using namespace std;

int N;
int arr[101];

void input() {
	cin >> N;
	int temp;
	for (int n = 0; n < N; n++) {
		cin >> temp;
		arr[temp] += 1;
	}
}

int find_max() {
	int result = 0;
	for (int i = 0; i <= 100; i++) {
		if (arr[i] > result) result = arr[i];
	}

	return N - result;
}

void solve() {
	input();
	cout << find_max();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}