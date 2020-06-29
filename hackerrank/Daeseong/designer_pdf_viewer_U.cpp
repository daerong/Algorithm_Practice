// start : am 10:28
// end : am 10:36

// find maximum height in given height array.
// And calculate max_height * given length

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define AL 26

int height_arr[AL];
int max_height = 0;

void solve() {
	for (int i = 0; i < AL; i++) {
		cin >> height_arr[i];
	}
	
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		int locate = str[i] - 'a';
		max_height = max(max_height, height_arr[locate]);
	}

	cout << max_height * str.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}