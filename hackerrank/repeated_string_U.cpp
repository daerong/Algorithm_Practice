// a의 갯수를 찾는 문제, 가장 많은 문자열의 반복으로 오해함.

#include <iostream>
#include <string>

using namespace std;

long long result;
long long N;
string str;
int str_vol;

void input() {
	cin >> str;
	str_vol = str.size();
	cin >> N;
}

long long find_same(char target) {
	long long repeat = N / str_vol;
	long long after = N % str_vol;

	long long repeat_sum = 0;

	for (int i = 0; i < str_vol; i++) {
		if (str[i] == target) {
			if (i < after) repeat_sum += repeat + 1;
			else repeat_sum += repeat;
		}
	}

	return repeat_sum;
}

void solve() {
	input();

	/*long long temp;
	for (int i = 0; i < str_vol; i++) {
		temp = find_same(str[i]);
		if (result < temp) result = temp;
	}*/

	result = find_same('a');

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}