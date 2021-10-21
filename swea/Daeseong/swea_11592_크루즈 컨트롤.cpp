#include <iostream>
#include <vector>

using namespace std;


double answer;
int T;

double D;
int N;
double K[2];
double S[2];

void input() {
	cin >> D >> N;

	answer = 0;

	for (int n = 0; n < N; n++) {
		cin >> K[n] >> S[n];
		double temp = (D - K[n]) / S[n];
		if (answer < temp) answer = temp;
	}
}

void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		answer = D / answer;
		cout << fixed;
		cout.precision(7);
		cout << "#" << t << " " << answer << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}