#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define V_MAX 100000 + 1
#define E_MAX 200000
typedef struct VERTEX {
	int node;
	long long edge;
}VERTEX;

using namespace std;

vector<VERTEX> vertex[V_MAX];
bool visited[V_MAX];
int V;
int E;
long long result;

bool operator<(VERTEX a, VERTEX b) {
	return a.edge > b.edge;				// top()À¸·Î min edge check;
}

void input() {
	cin >> V >> E;
	for (int v = 1; v <= V; v++) {
		vertex[v].clear();
		visited[v] = false;
	}
	int sp, ep;
	long long wt;
	for (int e = 0; e < E; e++) {
		cin >> sp >> ep >> wt;
		vertex[sp].push_back({ ep, wt });
		vertex[ep].push_back({ sp, wt });
	}
}
void prim() {
	priority_queue<VERTEX> pq;
	
	visited[1] = true;
	for (int v = 0; v < vertex[1].size(); v++) {
		pq.push(vertex[1][v]);
	}
	
	VERTEX temp;
	while (!pq.empty()) {
		temp = pq.top();
		pq.pop();

		if (visited[temp.node]) continue;

		result += temp.edge;
		visited[temp.node] = true;
		for (int v = 0; v < vertex[temp.node].size(); v++) {
			pq.push(vertex[temp.node][v]);
		}
	}
}
void solution() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		result = 0;
		input();
		prim();
		cout << "#" << tc << " " << result << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}