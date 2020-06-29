// start : am 00:00
// end : am 00:44

// 1918�⿡ 26.09.1918 �̰Ͷ����� ���� �ϳ��� ����� �ȵ�.
// �𸣸� ������ �������� Ǯ��...

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
			// ��
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
			// ��
			cout << "13.09." << year;
		}
		else {
			// ��
			if (year % 100) {
				cout << "12.09." << year;
			}
			else {
				// ��
				if (year % 400) {
					cout << "13.09." << year;
				}
				else {
					//��
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