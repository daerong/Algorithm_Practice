// start : pm 10:57
// translate : pm 11:14
// end : pm 11:48

// Solution
// 1. ���� ū ���� ã�´�.
// ����ó��) ���� ū ���� �ڽ��� ��ȣ���� ���� ��ġ�� ���� �� ����. (ū ���� �����θ� �̵� �����ϹǷ�)
// 2. ���� ū ���� �� ��ġ�� �´� ���, �� ���� ū ���� ã�´�.
// 3. ���� ū ���� �� ��ġ�� �ƴ� ���, �ٷ� �� ���ڿ� ��ġ�� �ٲ۴�.
// ����ó��) ��ġ�� �ٲ� �� �ִ� Ƚ���� 2ȸ


#include <iostream>

using namespace std;

#define N_MAX 100001

int T;
int N;
int arr[N_MAX];
int cost[N_MAX];

void show_arr() {
	for (int n = 1; n <= N; n++) {
		cout << arr[n] << " ";
	}

	cout << endl;
}

void arrange() {
	int last = N;
	int cnt = 0;
	int temp;
	for (int n = N; n >= 1; n--) {
		if (arr[n] != last) continue;		// ã�� �� ���� �̵�
		if (arr[n] == n) {						// �� ��ġ
			last -= 1;
			continue;
		}
		if (n >= last) {					// �Ұ����� ����, ū���� �����θ� �̵� ����
			cout << "Too chaotic" << endl;
			return;
		}

		if (cost[last] >= 2) {				// �Ұ����� ����, �̵����� 2��
			cout << "Too chaotic" << endl;
			return;
		}

		temp = arr[n];
		arr[n] = arr[n + 1];
		arr[n + 1] = temp;
		cnt += 1;
		cost[last] += 1;

		n += 2;			// ��ĭ ���̱� ����

		//show_arr();
	}

	cout << cnt << endl;
}

void solve() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;

		for (int n = 1; n <= N; n++) {
			cin >> arr[n];
			cost[n] = 0;
		}
		arrange();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}