#include <iostream>

using namespace std;

#define endl "\n"
#define ARR_MAX 61
#define NUM_MAX 1000000000000000000

long long arr[ARR_MAX];

void arr_setting() {
	arr[0] = 1;
	long long index = 1;
	for (int i = 1; i < ARR_MAX; i += 2) {
		index = index << 1;
		arr[i] = index;
		index = index * 2 + 1;
	}
	index = 1;
	for (int i = 2; i < ARR_MAX; i += 2) {
		index = index * 2 + 1;
		index = index << 1;
		arr[i] = index;
	}
}
int catch_T(long long n) {
	long long temp = 1;
	for (int i = 0; i < ARR_MAX; i++) {
		temp = temp << 1;
		if (n < temp) return i;
	}

	return -1;
}
void solution() {
	arr_setting();

	int TC;
	cin >> TC;
	
	long long N;
	int T;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N;
		T = catch_T(N);

		switch (T % 2) {
		case 0:
			if (N >= arr[T]) cout << "#" << tc << " Bob" << endl;
			else cout << "#" << tc << " Alice" << endl;
			break;
		case 1:
			if (N >= arr[T]) cout << "#" << tc << " Alice" << endl;
			else cout << "#" << tc << " Bob" << endl;
			break;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}