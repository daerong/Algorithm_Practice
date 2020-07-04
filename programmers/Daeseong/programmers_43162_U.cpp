// dfs

#include <string>
#include <vector>

using namespace std;

#define N_MAX 200
bool visited[N_MAX];

void connect(int *n, int target, vector<vector<int>> &computers) {
    visited[target] = true;
    for (int i = 0; i < *n; i++) {
        if (visited[i] || computers[target][i] == 0) continue;
        connect(n, i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer += 1;
            connect(&n, i, computers);
        }
    }
    return answer;
}