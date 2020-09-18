/*Solution
- 스테이지별 실패율의 내림차순으로 정렬하여 풀면 쉽게 해결할 수 있다.
- 문제풀이 과정은 다음과 같다.
- 1. int 배열에 stages의 각 숫자의 갯수를 저장한다. (해당 stage에서 실패)
- 2. 1 stage에 전원이 도전하고 이후로 매 스테이지 도전자가 차감된다.
- 2-1. priority queue에{ index, arr[i]/sum }을 push한다.
- 2-2. priority queue는 arr[i]/sum을 기준으로 내림차순 정렬한다.
- 2-3. sum = sum - arr[i]를 통해 차감한다.
- 2-4. sum이 0이 될때까지 반복한다. (도전자가 없음)
- 3. priority queue에서 순서대로 index를 뽑아 vector에 추가한다.
- 위 풀이 중 주의할 사항이 있다.
- 1. sum이 0이 되는 경우 연산을 실행할 수 없어 문제를 야기한다.
    - sum이 0인 경우는 arr[i] 값도 0이기 때문에 arr[i] == 0인 경우 0을 대입하는 방식으로 해결할 수 있다.*/ 

//#include <iostream>
// Code start

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct STAGE {
    int index;
    double rate;
} STAGE;

bool operator <(STAGE a, STAGE b) {
    if (a.rate == b.rate) return a.index > b.index;
    return a.rate < b.rate;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    priority_queue<STAGE> pq;

    int arr[502];
    for (int i = 0; i <= 501; i++) arr[i] = 0;
    for (vector<int>::iterator it = stages.begin(); it < stages.end(); it++) arr[*it] += 1;

    int sum = stages.size();
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 0) pq.push({ i, 0 });
        else {
            pq.push({ i, (double)arr[i] / sum });
            sum -= arr[i];
        }
    }

    STAGE temp;
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();

        answer.push_back(temp.index);
    }

    return answer;
}

// Code end
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int N = 4;
//    vector<int> stages;
//    stages.push_back(5);
//    stages.push_back(5);
//    stages.push_back(5);
//    stages.push_back(5);
//    stages.push_back(5);
//    stages.push_back(5);
//    stages.push_back(5);
//    stages.push_back(5);
//
//
//    vector<int> temp = solution(N, stages);
//    for (vector<int>::iterator iter = temp.begin(); iter < temp.end(); iter++) {
//        cout << *iter << endl;
//    }
//
//    return 0;
//}