//Solution
//- It is a problem easy to solve.
//- But you spend all step point, if you can't move about k step, print 'No'

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string given_str;
string target_str;
int limit;

void input() {
	cin >> given_str >> target_str >> limit;
}

bool solution() {
	int given_size = given_str.size();
	int target_size = target_str.size();
	int repeat_limit = min(given_size, target_size);
	int str_cnt = 0;
	for (int n = 0; n < repeat_limit; n++) {
		if (given_str[n] == target_str[n]) str_cnt++;
		else break;
	}

	int out_cnt = given_size - str_cnt;
	int in_cnt = target_size - str_cnt;

	if (given_size + target_size <= limit) {
		return true;
	}
	else if (out_cnt + in_cnt > limit) {
		return false;
	}
	else {
		int divide_two = out_cnt + in_cnt - limit;
		if (divide_two % 2) return false;
		else return true;
	}
}

void solve() {
	input();

	if (solution()) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}