//Solution
//- Map에서 키를 정수로 사용하여 속도를 높임.
//- Union-Find로 Parent 배열을 이용.
//- 입출력 성능 개선 endl -> "\n", ios_base::sync_with_stdio(), cin.tie()등 사용.
//- Find, getParent 함수에서 다시 찾는 것을 방지하기 위해 값 업데이트 필요.

#include <iostream>
#include <map>
#include <string>

using namespace std;
#define endl "\n"

map<string, int> m;
int parent[200002];
int friends[200002];

int getParent(int target) {
	if (target == parent[target]) return target;
	return parent[target] = getParent(parent[target]);
}

int Union(int one, int two) {
	one = getParent(one);
	two = getParent(two);

	if (one < two) {
		parent[two] = one;
		friends[one] += friends[two];
		return friends[one];
	}
	else if (one > two) {
		parent[one] = two;
		friends[two] += friends[one];
		return friends[two];
	}

	return friends[two];
}

void initalize(int N) {
	for (int i = 0; i <= (2 * N); i++) {
		parent[i] = i;
		friends[i] = 1;
	}

	m.clear();
}

void solve() {
	int TC;
	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		int N;
		cin >> N;

		initalize(N);

		string one, two;
		int index = 0;
		for (int i = 0; i < N; i++) {
			cin >> one >> two;
			if (m.count(one) == 0) m[one] = index++;
			if (m.count(two) == 0) m[two] = index++;

			cout << Union(m[one], m[two]) << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}