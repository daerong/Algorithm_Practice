// start : pm 12:36
// end : pm 12:51

// �ش� �������� �̵��ϴ� �� �Ѱܾ��ϴ� ������ ���� ���ϴ� ����
// ��ⷯ �������� ���� ���� �� �ִ�.
// �ڿ��� �ѱ�� ���� �ΰ��� �б�� ������� �Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

int result;

int n;
int p;

void input() {
	cin >> n >> p;
}

void turnning_page() {
	int right = p / 2;
	int left;		
	if (n % 2) left = (n - p)/2;
	else left = (n - p + 1)/2;

	result = min(right, left);
}

void solve() {
	input();
	turnning_page();

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}