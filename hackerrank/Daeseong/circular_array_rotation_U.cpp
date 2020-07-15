// start : am 12:20
// end : am 12:39

//Solution
//- When the k is equal to n, array 'a' keep original. So use MOD().
//- Each rotation is occur to change array. If k = 1, the last number have index = 0.
//- So you can find the rule, the larger 'k', the smaller index(index means frist number).
//- For example, if n is 4, a array is [1, 2, 3, 4]
//- k = 1 [4, ....], k = 2 [3, ....], k = 3 [2, ....]
//- if you want to get number at 'm'th, useing the formula (m - (k % n)).
//- When the result is under zero, add n.

#include <iostream>

using namespace std;

#define N_MAX 100000
int arr[N_MAX];

void solve() {
	int N, K, Q;
	cin >> N >> K >> Q;

	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}

	int index;
	for (int q = 0; q < Q; q++) {
		int m;
		cin >> m;
		index = m - (K % N);
		if (index < 0) index += N;
		cout << arr[index] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}