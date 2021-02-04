#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

#define N_MAX 100001

typedef struct NODE {
	int locate;
	int step;
} NODE;

int S;
int E;

void init() {
	cin >> S >> E;
}

int bfs() {
	if (S >= E) return S - E;
	unordered_map<int, int> m;
	queue<NODE> zero_q;
	queue<NODE> one_q;

	NODE temp;

	zero_q.push({ S, 0 });
	while (!zero_q.empty() || !zero_q.empty()) {
		while (!zero_q.empty()) {
			temp = zero_q.front();
			zero_q.pop();

			for (int k = temp.locate; k <= E * 2; k *= 2) {
				if (m.count(k) == 1) continue;
				m.insert({ k , temp.step });
				one_q.push({ k , temp.step });

				if (k == E) return temp.step;
			}
		}

		while (!one_q.empty()) {
			temp = one_q.front();
			one_q.pop();

			int locate;
			int next_step = temp.step + 1;
			if (temp.locate > 0) {
				locate = temp.locate - 1;
				if (m.count(locate) == 1) continue;
				m.insert({ locate , next_step });
				zero_q.push({ locate,next_step });

				if (locate == E) return next_step;
			}
			if (temp.locate < E) {
				locate = temp.locate + 1;
				if (m.count(locate) == 1) continue;
				m.insert({ locate , next_step });
				zero_q.push({ locate, next_step });

				if (locate == E) return next_step;
			}
		}
	}

	return -1;
}

void solution() {
	init();
	cout << bfs() << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}