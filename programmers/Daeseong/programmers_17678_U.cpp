//Solution
//- 각각의 상황에 맞는 결과를 출력하면 된다.
//- 0. 주어진 string 배열을 정렬한다.
//- 1. 각 버스는 최대 m명의 사람을 태운다.
//- 1-1. queue의 가장 앞사람이 버스 도착시간보다 작거나 같은 경우 queue에서 뺀다.
//- 1-2. 큰 경우 버스는 그냥 지나간다.
//- 1-3. queue가 비어있는 경우 버스 시간을 리턴한다.
//- 2. 마지막 버스가 지나갔다면 상황별로 아래 결과를 리턴한다.
//- 2-1. 마지막 버스가 남은 queue의 front보다 빠른경우, 버스 시간을 리턴한다.
//- 2-2. 마지막 버스가 남은 queue의 front보다 작거나 같은 경우 이 승객보다 1초 작은 시간을 리턴한다.


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string timeUp(string str, int up) {
    str[4] += up % 10;
    str[3] += up / 10;
    if (str[4] > '9') {
        str[3] += 1;
        str[4] -= 10;
    }
    if (str[3] >= '6') {
        str[1] += 1;
        str[3] -= 6;
    }
    if (str[1] > '9') {
        str[0] += 1;
        str[1] -= 10;
    }

    return str;
}

string timeDown(string str) {
    str[4] -= 1;
    if (str[4] < '0') {
        str[3] -= 1;
        str[4] += 10;
    }
    if (str[3] < '0') {
        str[1] -= 1;
        str[3] += 6;
    }
    if (str[1] < '0') {
        str[0] -= 1;
        str[1] += 10;
    }

    return str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "09:00";

    sort(timetable.begin(), timetable.end());
    queue<string, deque<string>> q(deque<string>(timetable.begin(), timetable.end()));

    string lastP;
    string lastB;
    for (int bus = 1; bus <= n; bus++) {
        if (answer > "23:59") return "23:59";
        for (int man = 1; man <= m; man++) {
            if (q.empty()) return answer;

            lastP = q.front();
            if (answer < lastP) break;
            q.pop();
        }

        lastB = answer;
        answer = timeUp(answer, t);
    }

    if (lastB < lastP) return lastB;
    else return timeDown(lastP);
}

//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n = 60;      // 회
//    int t = 60;      // 간격(분)
//    int m = 1;      // 명수
//    vector<string> timetable;
//    timetable.push_back("00:09");
//    timetable.push_back("00:10");
//    timetable.push_back("00:11");
//    timetable.push_back("00:12");
//    timetable.push_back("00:13");
//    timetable.push_back("00:14");
//    timetable.push_back("00:15");
//    timetable.push_back("00:16");
//    timetable.push_back("00:17");
//    timetable.push_back("00:18");
//    timetable.push_back("00:19");
//    timetable.push_back("00:20");
//    timetable.push_back("00:21");
//    timetable.push_back("00:22");
//    timetable.push_back("00:23");
//    timetable.push_back("00:24");
//    timetable.push_back("00:25");
//    timetable.push_back("00:26");
//    timetable.push_back("00:27");
//    timetable.push_back("00:28");
//    timetable.push_back("00:29");
//    timetable.push_back("00:30");
//    timetable.push_back("00:31");
//    timetable.push_back("00:32");
//
//    //int n = 2;      // 회
//    //int t = 1;      // 간격(분)
//    //int m = 2;      // 명수
//    //vector<string> timetable;
//    //timetable.push_back("08:00");
//    //timetable.push_back("08:00");
//    //timetable.push_back("08:00");
//    //timetable.push_back("09:00");
//    //timetable.push_back("09:05");
//
//    //int n = 1;      // 회
//    //int t = 1;      // 간격(분)
//    //int m = 5;      // 명수
//    //vector<string> timetable;
//    //timetable.push_back("08:00");
//    //timetable.push_back("08:01");
//    //timetable.push_back("08:02");
//    //timetable.push_back("08:03");
//
//    cout << solution(n, t, m, timetable);
//
//    return 0;
//}