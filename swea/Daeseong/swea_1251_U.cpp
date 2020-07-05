#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define N_MAX 1000
typedef struct EDGE {
	long long distance;
	long long start;
	long long end;
} EDGE;

using namespace std;

long long result;
int N;
long double E;
vector<EDGE> edge;
long long parent[N_MAX];
long long nx[N_MAX];
long long ny[N_MAX];

void input() {
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> nx[n];
	}
	for (int n = 0; n < N; n++) {
		cin >> ny[n];
	}

	long long dx, dy;
	for (int s = 0; s < N; s++) {
		for (int e = 0; e < N; e++) {
			dx = nx[s] - nx[e];
			dy = ny[s] - ny[e];
			edge.push_back({ dx * dx + dy * dy, s, e });
		}
	}

	cin >> E;
}
void initialize() {
	result = 0;
	edge.clear();
}
bool cmp(EDGE a, EDGE b) {
	return a.distance < b.distance;
}
long long Find(long long target) {
	if (parent[target] == target) return target;
	return parent[target] = Find(parent[target]);
}
void Union(long long s, long long e) {
	s = Find(s);
	e = Find(e);
	if (s == e) return;
	parent[e] = s;
}
bool has_cycle(long long s, long long e) {
	if (Find(s) == Find(e)) return true;
	return false;
}
void kruskal() {
	sort(edge.begin(), edge.end(), cmp);
	for (int n = 0; n < N; n++) {
		parent[n] = n;
	}
	for (int i = 0; i < edge.size(); i++) {
		if (has_cycle(edge[i].start, edge[i].end)) continue;
		Union(edge[i].start, edge[i].end);
		result += edge[i].distance;
	}
}
void solution(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		initialize();
		input();
		kruskal();

		cout << "#" << t << " " << (long long)round(result * E) << endl;
		//cout << "#" << t << " " << E << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}