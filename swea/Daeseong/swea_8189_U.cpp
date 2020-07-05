#include <iostream>

#define N_MAX 100

using namespace std;

int N;
int A;
int B;
int mails[N_MAX];

void input() {
	cin >> N >> A >> B;
	for (int n = 0; n < N; n++) {
		cin >> mails[n];
	}
}
void mail_check() {
	int oldest = 0;
	int cnt = 0;
	for (int n = 0; n < N; n++) {
		if (mails[n] - mails[oldest] > B) {
			int repeat = cnt / 2 + cnt % 2;
			for (int r = 0; r < repeat; r++) {
				cout << " " << mails[oldest] + B;
			}
			oldest += repeat;
			cnt -= repeat;
		}

		cnt += 1;
		if (cnt >= A) {
			int repeat = cnt / 2 + cnt % 2;
			for (int r = 0; r < repeat; r++) {
				cout << " " << mails[n];
			}
			oldest += repeat;
			cnt -= repeat;
		}
	}

	if (1000 - mails[oldest] >= B) {
		int repeat = cnt / 2 + cnt % 2;
		for (int r = 0; r < repeat; r++) {
			cout << " " << mails[oldest] + B;
		}
		oldest += repeat;
		cnt -= repeat;
	}

	for (int n = oldest; n < N; n++) {
		cout << " " << mails[n] + B;
	}
}
void solution() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		cout << "#" << t;
		mail_check();
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}