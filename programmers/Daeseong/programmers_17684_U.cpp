//Solution
//- Hashmap을 사용하면 쉽게 풀 수 있으나 다음에 유의한다.
//- 1. "A"의 인덱스는 1이다. 
//- 2. "A" ~ "Z" 범위를 우선 mapping한다.
//- 3. 최대길이의 문자열을 우선으로 확인한다.
//- 4. 검색 문자열이 발견되면 다음을 실행한다.
//- 4-1. answer에 index를 추가한다.
//- 4-2. 검색문자열 + 바로 뒤의 문자를 map에 추가한다.
//- 4-2-1. 4-2에서 바로 뒤의 문자가 없는 경우 무시한다.
//- 4-3. 4-2에서 추가한 문자열의 길이가 기존 최대값보다 클 경우 업데이트한다.
//- 4-4. 4에서 검색된 문자열을 제거한다.

#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    unordered_map<string, int> m;
    int m_index = 1;

    string temp = "A";
    for (int i = 0; i < 26; i++) {
        m.insert({ temp, m_index++ });
        temp[0] += 1;
    }

    int max_len = 1;

    while (!msg.empty()) {
        for (int len = max_len; len > 0; len--) {
            if (msg.length() < len) continue;
            if (m.count(msg.substr(0, len)) == 1) {
                //cout << "현재입력 : " << msg.substr(0, len) << endl;
                answer.push_back(m[msg.substr(0, len)]);
                if (msg.length() != len) {
                    //cout << "사전추가 : " << m_index << " : "<< msg.substr(0, len + 1) << endl;
                    m.insert({ msg.substr(0, len + 1), m_index++ });
                    max_len = max(max_len, len + 1);
                }

                msg.erase(0, len);
                break;
            }
        }
    }
 
    return answer;
}

//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    string msg = "TOBEORNOTTOBEORTOBEORNOT";
//    vector<int> result = solution(msg);
//    for (int i = 0; i < result.size(); i++) {
//        //cout << result[i] << endl;
//    }
//    
//
//    return 0;
//}