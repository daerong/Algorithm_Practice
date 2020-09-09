Solution
- 몇가지 단계를 거쳐서 답을 구해낼 수 있다.
- 1. 문자열을 자른다.
- 1-1. 공백을 기준으로 두번째 문자열을 초단위 완료시간으로 변환.
- 1-2. 공백을 기준으로 세번째 문자열을 초단위 처리시간으로 변환.

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