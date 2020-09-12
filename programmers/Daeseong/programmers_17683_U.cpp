//Solution
//- 문자열을 잘 잘라내면 어렵지 않게 풀 수 있다.
//- 다음에 유의하여 풀이할 것.
//- 1. 찾지 못하면 (NONE)을 출력할 것
//- 2. buffer size 는 최대 1439 * 2가 필요하다.
//- 3. C#과 같이 두개의 문자가 하나의 코드로 사용할 경우 길이가 1이다. 이를 치환하기 위해 소문자를 사용했다.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef struct MUSIC {
    int time;
    string name;
    string code;
} MUSIC;

bool operator <(MUSIC a, MUSIC b) {
    return a.time < b.time;
}

string solution(string m, vector<string> musicinfos) {
    priority_queue<MUSIC> pq;

    char* ptr;
    char buff[3000];

    for (int m_id = 0; m_id < musicinfos.size(); m_id++) {
        strcpy(buff, musicinfos[m_id].c_str());
        ptr = strtok(buff, ",:");
        int s_time = atoi(ptr) * 60;
        ptr = strtok(NULL, ",:");
        s_time += atoi(ptr);
        ptr = strtok(NULL, ",:");
        int e_time = atoi(ptr) * 60;
        ptr = strtok(NULL, ",:");
        e_time += atoi(ptr);
        ptr = strtok(NULL, ",:");
        string name = ptr;
        ptr = strtok(NULL, ",:");
        string code = ptr;

        pq.push({ e_time - s_time, name, code });
    }

    string::iterator it = m.begin();
    while (it < m.end()) {
        if (*it == '#') {
            m.erase(it);
            it--;
            *it += 32;
        }

        it++;
    }
    int m_len = m.length();

    MUSIC temp;
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();

        it = temp.code.begin();
        while (it < temp.code.end()) {
            if (*it == '#') {
                temp.code.erase(it);
                it--;
                *it += 32;
            }

            it++;
        }

        int len = temp.time;
        string song = "";
        while (len >= temp.code.length()) {
            song += temp.code;
            len -= temp.code.length();
        }
        song += temp.code.substr(0, len);

        if (song.find(m) != string::npos) return temp.name;
    }

    return "(None)";
}

//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    string m = "CC#BCC#BCC#BCC#B";
//    vector<string> musicinfos;
//    musicinfos.push_back("03:00,03:30,FOO,CC#B");
//    musicinfos.push_back("04:00,04:08,BAR,CC#BCC#BCC#B");
//
//    cout << solution(m, musicinfos);
//
//    return 0;
//}