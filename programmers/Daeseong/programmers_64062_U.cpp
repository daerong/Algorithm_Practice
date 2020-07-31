#include <string>
#include <vector>
#include <queue>
#include <cstring>

typedef struct UDS {
    int vol;
    int n;
};
bool operator<(UDS a, UDS b) {
    return a.vol < b.vol;
}

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 200000001;
    priority_queue<UDS> pq;
    for (int i = 0; i < stones.size(); i++) {
        pq.push({ stones[i], i });
    }

    UDS temp;
    bool visited[200000];
    memset(visited, 0, sizeof(visited));

    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();

        int target;

        for (int a = 0; a < k; a++) {
            target = temp.n - a;
            if (target < 0) break;
            if (visited[target]) continue;
            stones[target] = temp.vol;
            visited[target] = true;
        }
    }

    for (int a = 0; a <= stones.size() - k; a++) {
        answer = min(answer, stones[a]);
    }

    return answer;
}