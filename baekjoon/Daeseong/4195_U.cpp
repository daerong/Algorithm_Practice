#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> m;				// 이름, 인덱스
vector<pair<string, int>> vec;				// 이름, 카운트

int connection_update(string parent, int addition) {
	int parent_index = m[parent];
	if (vec[parent_index].first == parent) {
		vec[parent_index].second += addition;
		return vec[parent_index].second;
	}
	else {
		string next_target = vec[parent_index].first;
		return vec[parent_index].second = connection_update(next_target, addition);
	}
}

void add_friend(int connection_cnt) {
	vec.push_back(make_pair("None", 0));
	string one;
	string two;
	for (int i = 0; i < connection_cnt; i++) {
		cin >> one >> two;

		if (m[two] != 0) {
			if (m[one] != 0) {
				int add_factor = connection_update(one, 0);
				m[one] = m[two];

				vec[m[one]].second = connection_update(two, add_factor);

				cout << vec[m[one]].second << endl;
			}
			else {
				vec.push_back(make_pair(one, 1));
				m[one] = m[two];

				vec[m[one]].second = connection_update(two, 1);

				cout << vec[m[one]].second << endl;
			}
		}
		else {
			if (m[one] == 0) {
				vec.push_back(make_pair(one, 1));
				m[one] = vec.size();
			}
			vec.push_back(make_pair(two, 1));
			m[two] = m[one];

			vec[m[two]].second = connection_update(one, 1);

			cout << vec[m[two]].second << endl;
		}
	}

	m.clear();
	vec.clear();
}

void solve() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		int N;
		cin >> N;
		add_friend(N);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}