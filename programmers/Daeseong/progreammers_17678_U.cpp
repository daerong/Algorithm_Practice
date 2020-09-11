#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    int capacity = n * t * m;
    sort(timetable.begin(), timetable.end());

    queue<string, deque<string>> q(deque<string>(timetable.begin(), timetable.end()));

    int busCnt = 0;
    int hh = 9;
    int mm = 0;
    string timeStr;
    string tempQ;

    for (int nn = 0; nn < n; nn++) {
        if (hh < 10) timeStr = '0' + to_string(hh) + ':';
        else timeStr = to_string(hh) + ':';
        if (mm < 10) timeStr += '0' + to_string(mm);
        else timeStr += to_string(mm);
        
        for (int i = 0; i < m; i++) {
            if (q.empty()) return timeStr;
            tempQ = q.front();
            if (timeStr < tempQ) break;
            q.pop();
        }

        mm += t;
        if (mm >= 60) {
            hh += 1;
            mm -= 60;
        }

        if (hh >= 24) {
            timeStr = tempQ;
            hh = stoi(timeStr.substr(0));
            mm = stoi(timeStr.substr(3));

            if (mm - 1 < 0) {
                hh -= 1;
                mm = 59;
            }
            else {
                mm -= 1;
            }

            if (hh < 10) timeStr = '0' + to_string(hh) + ':';
            else timeStr = to_string(hh) + ':';
            if (mm < 10) timeStr += '0' + to_string(mm);
            else timeStr += to_string(mm);

            return timeStr;
        }
    }

    if (timeStr > "23:59") return "23:59";
    if (timetable.size() == q.size()) return timeStr;

   

    timeStr = timetable[timetable.size() - q.size() - 1];
    hh = stoi(timeStr.substr(0));
    mm = stoi(timeStr.substr(3));

    if (mm - 1 < 0) {
        hh -= 1;
        mm = 59;
    }
    else {
        mm -= 1;
    }
    
    if (hh < 10) timeStr = '0' + to_string(hh) + ':';
    else timeStr = to_string(hh) + ':';
    if (mm < 10) timeStr += '0' + to_string(mm);
    else timeStr += to_string(mm);

    return timeStr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 60;      // 회
    int t = 60;      // 간격(분)
    int m = 1;      // 명수
    vector<string> timetable;
    timetable.push_back("00:09");
    timetable.push_back("00:10");
    timetable.push_back("00:11");
    timetable.push_back("00:12");
    timetable.push_back("00:13");
    timetable.push_back("00:14");
    timetable.push_back("00:15");
    timetable.push_back("00:16");
    timetable.push_back("00:17");
    timetable.push_back("00:18");
    timetable.push_back("00:19");
    timetable.push_back("00:20");
    timetable.push_back("00:21");
    timetable.push_back("00:22");
    timetable.push_back("00:23");
    timetable.push_back("00:24");
    timetable.push_back("00:25");
    timetable.push_back("00:26");
    timetable.push_back("00:27");
    timetable.push_back("00:28");
    timetable.push_back("00:29");
    timetable.push_back("00:30");
    timetable.push_back("00:31");
    timetable.push_back("00:32");

    //int n = 2;      // 회
    //int t = 1;      // 간격(분)
    //int m = 2;      // 명수
    //vector<string> timetable;
    //timetable.push_back("08:00");
    //timetable.push_back("08:00");
    //timetable.push_back("08:00");
    //timetable.push_back("09:00");
    //timetable.push_back("09:05");

    //int n = 1;      // 회
    //int t = 1;      // 간격(분)
    //int m = 5;      // 명수
    //vector<string> timetable;
    //timetable.push_back("08:00");
    //timetable.push_back("08:01");
    //timetable.push_back("08:02");
    //timetable.push_back("08:03");

    cout << solution(n, t, m, timetable);

    return 0;
}