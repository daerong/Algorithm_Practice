//Solution
//- day 15 Hackos
//- month 500 Hackos
//- year 10000 Hackos

#include <iostream>

using namespace std;

long long dd[2];
long long mm[2];
long long yy[2];

void input() {
	for (int i = 0; i < 2; i++) {
		cin >> dd[i] >> mm[i] >> yy[i];
	}
}

void solve() {
	long long result = 0;
	input();
	if (dd[0] > dd[1] && mm[0] == mm[1] && yy[0] == yy[1]) result = 15 * (dd[0] - dd[1]);
	else if (mm[0] > mm[1] && yy[0] == yy[1]) result = 500 * (mm[0] - mm[1]);
	else if (yy[0] > yy[1])result = 10000;
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}