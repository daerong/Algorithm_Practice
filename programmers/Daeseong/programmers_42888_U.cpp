//Solution
//- 문제는 쉽게 이해했으나 문자열 입력에서 문제가 있었다.
//- 풀이과정은 다음과 같다.
//- 1. 문자를 3개로 나눈다.
//    - 문자는 command, user, nickname 세개 섹션으로 나누며 마지막 nickname은 없을 수도 있다.
//    - 여기서 공백문자(' ')를 찾아 나누는 방식을 이용하니 테스트케이스에서 마구 실패가 떴다.
//    - 이를 stringstream 객체로 받아 처리하니 모두 통과됐다. 
//- 2. 명령어에 따라 다음을 수행한다.
//- 2-1. 명령어 == Enter
//- 2-1-1. user가 처음 등장한 경우, map<string, index>에 넣는다.
//- 2-1-2. map에서 user의 index를 찾는다.
//- 2-1-3. string 배열의 index번째 원소를 nickname으로 치환한다.
//- 2-1-4. user에 대한 명령어(들어옴)을 큐에 추가한다.
//- 2-2. 명령어 == Leave
//- 2-2-1. map에서 user의 index를 찾는다.
//- 2-2-2. user에 대한 명령어(나감)을 큐에 추가한다.
//- 2-3. 명령어 == Change
//- 2-3-1. map에서 user의 index를 찾는다.
//- 2-3-2. string 배열의 index번째 원소를 nickname으로 치환한다.
//- 3. 큐를 순회하며 다음을 실행한다.
//- 3-1. 큐에서 원소를 하나 빼낸다.
//- 3-2. user를 찾아 index를 가져온다.
//- 3-3. string 배열에서 index번째 원소(= 최종이름)를 가져온다.
//- 3-4. 큐의 명령어(들어옴 or 나감)을 판단하여 다음을 실행한다.
//- 3-2-1. if 들어옴 : 최종이름 + "님이 들어왔습니다."
//- 3-2-2. if 나감 : 최종이름 + "님이 나갔습니다."
//- 3-5. 3-4에서 얻은 스트링을 결과에 추가한다.

//#include <iostream>
// Code start

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

typedef struct MSG {
    int m_id;
    bool type;
};

vector<string> solution(vector<string> record) {
    vector<string> answer;

    queue<MSG> q;
    unordered_map<string, int> m;
    int m_id = 0;
    string name[100000];
    string command, user, nickname;
    stringstream ss;

    for (vector<string>::iterator iter = record.begin(); iter < record.end(); iter++) {
        ss.str(*iter);
        ss >> command;
        ss >> user;
        ss >> nickname;

        if (command == "Enter") {
            if (m.count(user) == 0) {
                m.insert({ user, m_id++ });
            }
            name[m[user]] = nickname;
            q.push({ m[user], true });
        }
        else if (command == "Leave") {
            q.push({ m[user], false });
        }
        else if (command == "Change") {
            name[m[user]] = nickname;
        }

        ss.clear();
    }

    MSG temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp.type) answer.push_back(name[temp.m_id] + "님이 들어왔습니다.");
        else answer.push_back(name[temp.m_id] + "님이 나갔습니다.");
    }

    return answer;
}

// Code end
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    vector<string> record;
//    record.push_back("Enter uid0606 Prodo");
//    record.push_back("Change uid0606 Ryan");
//    record.push_back("Leave uid0606");
//
//    vector<string> temp = solution(record);
//    for (vector<string>::iterator iter = temp.begin(); iter < temp.end(); iter++) {
//        cout << *iter << endl;
//    }
//
//    return 0;
//}