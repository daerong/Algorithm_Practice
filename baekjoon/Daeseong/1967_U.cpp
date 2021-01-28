#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 10002

typedef struct NODE {
	int left;
	int right;
} NODE;

typedef struct EDGE {
	int left;
	int right;
}EDGE;

int N;
NODE node[N_MAX];
EDGE edge[N_MAX];
EDGE weight[N_MAX];
int answer;

void init() {
	cin >> N;
	int s, e, w;
	for (int n = 1; n < N; n++) {
		cin >> s >> e >> w;
		if (node[s].left == 0) {
			node[s].left = e;
			edge[s].left = w;
		}
		else {
			node[s].right = e;
			edge[s].right = w;
		}
	}
}

int expand(int target) {
	if (edge[target].left == 0 && edge[target].right == 0) return 0;
	if (weight[target].left == 0) weight[target].left = edge[target].left + expand(node[target].left);
	if (weight[target].right == 0) weight[target].right = edge[target].right + expand(node[target].right);
	return max(weight[target].left, weight[target].right);
}

void solution() {
	init();
	for (int i = 1; i <= N; i++) {
		expand(i);
		answer = max(answer, weight[i].left + weight[i].right);
	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}