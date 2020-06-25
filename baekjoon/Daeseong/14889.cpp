#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result = 1000000000;

int N;
int T;

int board[20][20];
bool checked[20] = {false};

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	T = N / 2;
}

void match(int num, int cnt) {
	if (cnt == T) {

		vector<int> team_link, team_start;
		for (int i = 0; i < N; i++) {
			if (checked[i]) team_link.push_back(i);
			else team_start.push_back(i);
		}

		int link_sum = 0;
		int start_sum = 0;

		for (int i = 0; i < T; i++) {
			for (int j = i + 1; j < T; j++) {
				int start_i = team_start[i];
				int start_j = team_start[j];
				int link_i = team_link[i];
				int link_j = team_link[j];
				link_sum += board[link_i][link_j] + board[link_j][link_i];
				start_sum += board[start_i][start_j] + board[start_j][start_i];
			}
		}

		result = min(result, abs(start_sum - link_sum));
		return;
	}

	for (int i = num + 1; i < N; i++) {
		if (checked[i] == false) {
			checked[i] = true;
			match(i, cnt + 1);
			checked[i] = false;
		}
	}
}

void solve() {
	input();
	match(0, 0);
	cout << result;
}


int main() {
	solve();
	return 0;
}