// start : pm 5:42
// end : pm 5:54
// 모두 더한 값을 SUM이라 할 때 배열의 최대값을 빼면 SUM의 최소값이, 최소값을 빼면 SUM의 최댓값이다.
// vector-sort를 사용해 내림차순으로 정렬하여 값을 구했다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long result_min;
long result_max;
long sum;

vector<long> vec;

void input() {
	long temp;
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		sum += temp;
		vec.push_back(temp);
	}
}

void find_result() {
	sort(vec.begin(), vec.end());
	result_max = sum - vec.front();
	result_min = sum - vec.back();
}

void solve() {
	input();
	find_result();

	cout << result_min << " " << result_max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}