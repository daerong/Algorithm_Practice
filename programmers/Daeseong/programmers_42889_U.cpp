/*Solution
- ���������� �������� ������������ �����Ͽ� Ǯ�� ���� �ذ��� �� �ִ�.
- ����Ǯ�� ������ ������ ����.
- 1. int �迭�� stages�� �� ������ ������ �����Ѵ�. (�ش� stage���� ����)
- 2. 1 stage�� ������ �����ϰ� ���ķ� �� �������� �����ڰ� �����ȴ�.
- 2-1. priority queue��{ index, arr[i]/sum }�� push�Ѵ�.
- 2-2. priority queue�� arr[i]/sum�� �������� �������� �����Ѵ�.
- 2-3. sum = sum - arr[i]�� ���� �����Ѵ�.
- 2-4. sum�� 0�� �ɶ����� �ݺ��Ѵ�. (�����ڰ� ����)
- 3. priority queue���� ������� index�� �̾� vector�� �߰��Ѵ�.
- �� Ǯ�� �� ������ ������ �ִ�.
- 1. sum�� 0�� �Ǵ� ��� ������ ������ �� ���� ������ �߱��Ѵ�.
    - sum�� 0�� ���� arr[i] ���� 0�̱� ������ arr[i] == 0�� ��� 0�� �����ϴ� ������� �ذ��� �� �ִ�.*/ 

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