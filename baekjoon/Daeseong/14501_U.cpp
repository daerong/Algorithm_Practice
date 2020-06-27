#include <iostream>

using namespace std;

int result = 0;

int N = 0;

typedef struct PLAN {
	int start;
	int end;
	int price;
} PLAN;

PLAN board[16];

void input() {
	cin >> N;

	int term;
	int price;

	for (int day = 1; day <= N; day++) {
		cin >> term >> price;
		board[day].start = day;
		board[day].end = day + term - 1;
		board[day].price = price;
	}

}

void see_table() {
	for (int i = 1; i <= N; i++) {
		cout << board[i].start << ", " << board[i].end << ", " << board[i].price << endl;
	}
}

void update_result(int target) {
	if (result < target) result = target;
}

void solution() {
	for (int day = 1; day <= N; day++) {
		if (board[day].end > N) continue;
		PLAN under_max = {0, 0, 0};
		for (int i = 1; i < day; i++) {
			if (board[i].end < board[day].start) {
				if (under_max.price < board[i].price) {
					under_max = board[i];
				}
			}
		}

		if (under_max.price != 0) {
			board[day].start = under_max.start;
			board[day].price += under_max.price;
		}
/*
		see_table();*/

		update_result(board[day].price);
	}
}

void solve() {
	input();
	solution();
	
	cout << result;
}

int main() {
	solve();
	return 0;
}