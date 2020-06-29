// start : am 00:00
// end : am 00:44

// 1918년에 26.09.1918 이것때문에 테케 하나가 통과가 안됨.
// 모르면 번역기 돌려보고 풀기...

#include <iostream>
#include <string>

using namespace std;

int year;

void input() {
	cin >> year;
}
	
void solution() {
	if (year < 1918) {
		if (year % 4) {
			// 평
			cout << "13.09." << year;
		}
		else {
			cout << "12.09." << year;
		}
	}
	else if (year == 1918) {
		cout << "26.09." << year;
	}
	else {
		if (year % 4) {
			// 평
			cout << "13.09." << year;
		}
		else {
			// 윤
			if (year % 100) {
				cout << "12.09." << year;
			}
			else {
				// 평
				if (year % 400) {
					cout << "13.09." << year;
				}
				else {
					//윤
					cout << "12.09." << year;
				}
			}
		}
	}
	
}

void solve() {
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}