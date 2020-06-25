#include <iostream>
#include <cstring>

using namespace std;

typedef enum LOCATE {U, D, L, R} LOCATE;
#define MAX 20
int Mx = 0;
int N;
int Bd[MAX][MAX] = {-1};

// U, D, L, R
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Bd[i][j];
		}
	}
}

//void showBdCp() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << BdCp[i][j];
//		}
//		cout << endl;
//	}
//}

void find_max(int target[MAX][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (target[i][j] > Mx) Mx = target[i][j];
		}
	}
}

void move(int New_BdCp[MAX][MAX], LOCATE dir, int cnt) {
	if (cnt > 5) {
		find_max(New_BdCp);
		return;
	}

	int BdCp[MAX][MAX];
	memcpy(BdCp, New_BdCp, sizeof(int)*MAX*MAX);

	switch (dir) {
	case U:
		for (int j = 0; j < N; j++) {
			int *old = NULL;
			for (int i = 0; i < N; i++) {
				if (BdCp[i][j] == 0) continue;
				else {
					if (old == NULL) {
						old = &BdCp[i][j];
					}
					else if (*old == BdCp[i][j]) {
						*old *= 2;					// 비트연산으로 변경
						BdCp[i][j] = 0;
						old = NULL;
					}
					else {
						old = &BdCp[i][j];
					}
				}
			}
		}
		break;
	case D:
		for (int j = 0; j < N; j++) {
			int *old = NULL;
			for (int i = N -1; i >= 0; i--) {
				if (BdCp[i][j] == 0) continue;
				else {
					if (old == NULL) {
						old = &BdCp[i][j];
					}
					else if (*old == BdCp[i][j]) {
						*old *= 2;					// 비트연산으로 변경
						BdCp[i][j] = 0;
						old = NULL;
					}
					else {
						old = &BdCp[i][j];
					}
				}
			}
		}
		break;
	case L:
		for (int i = 0; i < N; i++) {
			int *old = NULL;
			for (int j = 0; j < N; j++) {
				if (BdCp[i][j] == 0) continue;
				else {
					if (old == NULL) {
						old = &BdCp[i][j];
					}
					else if (*old == BdCp[i][j]) {
						*old *= 2;					// 비트연산으로 변경
						BdCp[i][j] = 0;
						old = NULL;
					}
					else {
						old = &BdCp[i][j];
					}
				}
			}
		}
		break;
	case R:
		for (int i = 0; i < N; i++) {
			int *old = NULL;
			for (int j = N - 1; j >= 0; j--) {
				if (BdCp[i][j] == 0) continue;
				else {
					if (old == NULL) {
						old = &BdCp[i][j];
					}
					else if (*old == BdCp[i][j]) {
						*old *= 2;					// 비트연산으로 변경
						BdCp[i][j] = 0;
						old = NULL;
					}
					else {
						old = &BdCp[i][j];
					}
				}
			}
		}
		break;

	}

	switch (dir) {
	case U:
		for (int j = 0; j < N; j++) {
			int nU = 0;
			for (int i = 0; i < N; i++) {
				if (BdCp[i][j] == 0) continue;
				else if (nU == i) {
					nU++;
					continue;
				}
				else {
					BdCp[nU++][j] = BdCp[i][j];
					BdCp[i][j] = 0;
				}
			}
		}
		break;
	case D:
		for (int j = 0; j < N; j++) {
			int nD = N - 1;
			for (int i = N - 1; i >= 0; i--) {
				if (BdCp[i][j] == 0) continue;
				else if (nD == i) {
					nD--;
					continue;
				}
				else {
					BdCp[nD--][j] = BdCp[i][j];
					BdCp[i][j] = 0;
				}
			}
		}
		break;
	case L:
		for (int i = 0; i < N; i++) {
			int nL = 0;
			for (int j = 0; j < N; j++) {
				if (BdCp[i][j] == 0) continue;
				else if (nL == j) {
					nL++;
					continue;
				}
				else {
					BdCp[i][nL++] = BdCp[i][j];
					BdCp[i][j] = 0;
				}
			}
		}
		break;
	case R:
		for (int i = 0; i < N; i++) {
			int nR = N - 1;
			for (int j = N - 1; j >= 0; j--) {
				if (BdCp[i][j] == 0) continue;
				else if (nR == j) {
					nR--;
					continue;
				}
				else {
					BdCp[i][nR--] = BdCp[i][j];
					BdCp[i][j] = 0;
				}
			}
		}
		break;
	}
	move(BdCp, U, cnt + 1);
	move(BdCp, D, cnt + 1);
	move(BdCp, L, cnt + 1);
	move(BdCp, R, cnt + 1);
}

void solve() {
	input();
	move(Bd, U, 1);
	move(Bd, D, 1);
	move(Bd, L, 1);
	move(Bd, R, 1);
}

int main(){
	solve();

	cout << Mx;
	return 0;
}