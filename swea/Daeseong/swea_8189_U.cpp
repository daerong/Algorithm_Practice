#include <iostream>

#define N_MAX 100
#define H_MAX 2000

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
	int cnt = 0;
	int oldest = 0;
	int now = 0;
	for (int h = 1; h <= H_MAX; h++) {
		if (mails[now] == h) {
			cnt += 1;
			now += 1;
		}

		if (cnt >= A) {
			int repeat = cnt / 2 + cnt % 2;
			cnt -= repeat;
			repeat += oldest;
			for (oldest; oldest < repeat; oldest++) {
				mails[oldest] = h;
			}
		}

		if (h - mails[oldest] == B) {
			int repeat = cnt / 2 + cnt % 2;
			cnt -= repeat;
			repeat += oldest;
			for (oldest; oldest < repeat; oldest++) {
				mails[oldest] = h;
			}
		}
	}
}
void print_times(int t) {
	cout << "#" << t;
	for (int n = 0; n < N; n++) {
		cout << " " << mails[n];
	}
	cout << endl;
}
void solution() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		mail_check();
		print_times(t);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}