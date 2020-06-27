#include <iostream>

using namespace std;

int nMin = 1000000001;
int nMax = -1000000001;

int N;
int num[11];
// +, -, *, /
int calc[4];


void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> calc[i];
	}
}

void calculation(int result, int index, int add, int sub, int multi, int devi) {
	if (add + sub + multi + devi == 0) {		// 연산자 더 없으면
		if (nMin > result) nMin = result;
		if (nMax < result) nMax = result;
	}
	else {
		if (add != 0) calculation(result + num[index], index + 1, add - 1, sub, multi, devi);
		if (sub != 0) calculation(result - num[index], index + 1, add, sub - 1, multi, devi);
		if (multi != 0) calculation(result * num[index], index + 1, add, sub, multi - 1, devi);
		if (devi != 0) calculation(result / num[index], index + 1, add, sub, multi, devi - 1);
	}
}


void solve() {
	input();
	calculation(num[0], 1, calc[0], calc[1], calc[2], calc[3]);

	cout << nMax << endl;
	cout << nMin << endl;
}

int main() {
	solve();
	return 0;
}