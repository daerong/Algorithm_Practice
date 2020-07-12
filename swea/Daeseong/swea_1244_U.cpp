#include <iostream>
#include <string>
#include <queue>

using namespace std;

string given_num;
int given_cnt;
int N;

void input() {
	cin >> given_num >> given_cnt;
	N = given_num.length();
}
string solution() {
	priority_queue<char> pq;
	string result = given_num;
	for (int i = 0; i < N; i++) {
		pq.push(given_num[i]);
	}

	int diffrent = 0;
	int index = 0;
	while (!pq.empty()) {
		char temp = pq.top();
		pq.pop();

		result[index] = temp;
		if (given_num[index] != temp) diffrent++;
		index++;
	}

	if (diffrent / 2 <= given_cnt) {
		return result;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (given_cnt == 0) break;
			if (result[i] == given_num[i]) continue;
			for (int j = N - 1; j > i; j--) {
				if (result[i] == given_num[j]) {
					given_num[j] = given_num[i];
					given_num[i] = result[i];
					given_cnt--;
					break;
				}
			}
		}

		return given_num;
	}
}

void solve() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		
		input();
		cout << "#" << tc << " " << solution() << endl;;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}