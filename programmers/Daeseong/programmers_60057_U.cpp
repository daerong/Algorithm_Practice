//Solution
//- 문자열 압축 문제.
//- 주의해야 할 사항
//- 1. 문자열을 절반으로 나눌 때, s.length() / 2 + 1를 사용한다.
//- 풀이과정은 다음과 같다.
//- 1. 자를 길이 len을 순차적으로 증가시키며 다음을 실행한다. (문자열의 절반길이 까지)
//- 1.1. map에 각 문자열을 잘라 index를 부여한다.
//- 1.2. 잘라진 문자열에 대한 index를 vector에 넣는다.
//- 1.3. vector에 대해 다음을 수행한다.
//- 1.3.1. 앞 index와 현재 index가 같으면, 다음을 수행한다.
//- 1.3.1.1. 길이를 len만큼 감소시킨다.
//- 1.3.1.2. cnt를 1증가시킨다.
//- 1.3.2. 앞 index와 현재 index가 다르면, 다음을 수행한다.
//- 1.3.2.1. cnt가 2이상이면 숫자의 길이만큼 answer에 더한다. (ex> 5면 1을, 20은 2를, 101은 3을 더함) 
//- 1.3.2.2. cnt를 1로 만든다.
//- 2. 남은 길이를 출력한다.

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int get_len(int target) {
    if (target < 10) return 1;
    if (target < 100) return 2;
    if (target < 1000) return 3;
    if (target < 10000) return 4;
    return -1;
}

int divide(string s, int len) {
    unordered_map<string, int> m;
    int m_index = 1;
    vector<int> vec;

    for (int i = 0; i + len <= s.length(); i += len) {
        string temp = s.substr(i, len);
        if (m.count(temp) == 0) m.insert({ temp, m_index++ });
        vec.push_back(m[temp]);
    }

    int answer = s.length();
    int before = -1;
    int cnt = 1;

    for (int i = 0; i < vec.size(); i++) {
        if (before != vec[i]) {
            if (cnt >= 2) answer += get_len(cnt);
            before = vec[i];
            cnt = 1;
        }
        else {
            answer -= len;
            cnt++;
        }
    }

    if (cnt >= 2) answer += get_len(cnt);

    return answer;
}

int solution(string s) {
    int answer = 1000000000;

    for (int len = 1; len <= s.length() / 2 + 1; len++) answer = min(answer, divide(s, len));

    return answer;
}