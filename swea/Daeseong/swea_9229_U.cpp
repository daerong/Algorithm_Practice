// start : pm 1:07
// end : pm 1:35

// To solve this problem is not need to BP algorithm.
// When the array of snack's weight, you can find the answer less comparation.
// So, I use vector & sort. Using array which sorted by descending order, doesn't occured move to back direction.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC;		// 테케 수
vector<int> snack;

int each_case() {
	int result = -1;

	int N;		// 과자 수
	int M;		// 무게 제한
	cin >> N >> M;
	int temp;
	for (int n = 0; n < N; n++) {
		cin >> temp;
		snack.push_back(temp);
	}

	sort(snack.begin(), snack.end(), greater<int>());
	int start = 0;
	int end = snack.size() - 1;

	while (start < end) {
		if (snack[start] + snack[end] > M) {
			start += 1;
		}
		else if (snack[start] + snack[end] == M) {
			result = M;
			break;
		}
		else {
			result = max(result, snack[start] + snack[end]);
			end -= 1;
		}
	}

	snack.clear();

	return result;
}

void solution() {
	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cout << "#" << tc + 1 << " " << each_case() << endl;;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}