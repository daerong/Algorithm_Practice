// start : pm 9:53
// end :
// try : 

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#define N_MAX 1000002

bool visited[N_MAX];
int N;
int result;

int solution(vector<int> money) {
    int answer = 0;
    // 초기화섹션
    // money_sum 초기화 필요시 작성
    // 초기화섹션

    priority_queue<pair<int, int>> pq;
    N = money.size();
    for (int n = 1; n <= N; n++) {
        pq.push({ money[n - 1], n });
    }

    pair<int, int> temp;
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();

        if (visited[temp.second - 1] || visited[temp.second + 1]) continue;
        
        visited[temp.second] = true;
        answer += temp.first;
    }
    
    return answer;
}

int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(1);
    cout << solution(vec);
    return 0;
}