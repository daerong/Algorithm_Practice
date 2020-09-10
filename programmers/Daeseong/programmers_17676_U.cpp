//Solution
//- 몇가지 단계를 거쳐서 답을 구해낼 수 있다.
//- 1. 문자열을 자른다.
//- 1-1. 공백을 기준으로 두번째 문자열을 초단위 완료시간으로 변환.
//- 1-2. 공백을 기준으로 세번째 문자열을 초단위 처리시간으로 변환.
//- 2. 1에서 처리된 시간을 우선순위큐(시간에 대한 오름차순)에 넣는다.
//- 2-1. 완료시간을 인덱스와 함께 큐에 넣는다.
//- 2-2. 시작시간(완료시간 - 처리시간 + 0.1)을 인덱스와 함께 큐에 넣는다.
//- 3. 우선순위 큐에서 하나씩 빼면서 다음을 실행한다.
//    - 인덱스가 처음 나오면 시작을 의미하고 다음 나오면 종료를 의미한다.
//- 3-1. 인덱스가 처음 나왔을 때, 다음을 실행한다.
//- 3-1-1. 종료시간을 리스트에 추가한다.
//- 3-2. 인덱스가 다음 나왔을 때, 다음을 실행한다.
//- 3-2-1. 시작시간을 리스트에 추가한다.
//- 3-2-2. 1초를 기준으로 그 시간 이전에 종료된 작업을 모두 시작시간 리스트에서 제거한다.
//- 3-2-3. 시작시간 리스트에 남아있는 갯수가 바로 1초간의 작업량이며 이를 최대값과 비교하여 업데이트한다.
//- 4. 3을 반복하여 1초간 작업량의 최대값을 리턴한다.

#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
//#include <iostream>

using namespace std;

typedef struct UDS {
    int index;
    double time;
} UDS;

bool operator <(UDS a, UDS b) {
    return a.time > b.time;
}

int solution(vector<string> lines) {
    unsigned int answer = 0;

    priority_queue<UDS> pq;
    int n = lines.size();
    bool *checked = new bool[n];
    for (int i = 0; i < n; i++) checked[i] = false;
    
    string temp_time;
    double duration;
    double time[3];
    double end_time;
    for (int i = 0; i < n; i++) {
        temp_time = lines[i].substr(11, 12);
        duration = stod(lines[i].substr(24));
        time[0] = stod(temp_time.substr(0, 2));
        time[1] = stod(temp_time.substr(3, 2));
        time[2] = stod(temp_time.substr(6, 6));
        end_time = time[0] * 3600 + time[1] * 60 + time[2];
        pq.push({i, end_time});
        pq.push({i, end_time - duration + 0.001});
    }

    list<int> lli;
    list<UDS> llo;
    UDS temp;
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();
        if (checked[temp.index]) {
            llo.push_back(temp);
        }
        else {
            lli.push_back(temp.index);
            checked[temp.index] = true;
            for (int i = 0; i < llo.size(); i++) {
                UDS f = llo.front();
                if (f.time + 1 <= temp.time) {
                    llo.pop_front();
                    lli.remove(f.index);
                    continue;
                }

                break;
            }

            answer = max(answer, (unsigned int)lli.size());
        }
    }

    return answer;
}

//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    vector<string> lines;
//    lines.push_back("2016-09-15 01:00:04.001 2.0s");
//    lines.push_back("2016-09-15 01:00:07.000 2s");
//
//    cout << solution(lines);
//    
//    return 0;
//}