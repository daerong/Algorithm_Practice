//Solution
//- Using Hashmap.
//- 해당 문제는 다음과 같이 풀 수 있다.
//- 1. 주어진 문자열을 각각 2 길이의 sub string으로 바꾼다.
//- 2. 나누어진 문자열의 그룹간 비교를 실행하여 교집합과 합집합의 원소갯수를 얻는다.
//- 3. 교집합 / 합집합 * 65536의 값을 리턴한다(소숫점 이하 버림).
//- 문제를 풀이한 과정은 다음과 같다.
//- 1. substring으로 1번 문자열을 2 길이로 자른다.
//- 2. Hashmap에 <문자열, 인덱스> 형태로 보관한다. 
//- 2-1. 1번 과정에서 같은 문자열이 발생할 수 있으므로 Hashmap에서 확인한다.
//- 2-2. 같은 문자열에 대한 count는 별도의 cnt 배열을 추가해 저장한다.
//- 3. substring으로 2번 문자열을 2 길이로 자른다.
//- 4. Hashmap에 <문자열, 인덱스> 형태로 보관한다. 단, 인덱스는 1번과 동일하게 사용한다.
//- 4-1. 2번 문자열에서는 1번에서 발생하지 않은 문자열이 발생할 수 있다. 이 경우 1번 이후의 인덱스를 사용하여 저장한다.
//- 5. 1번 문자열에 대한 인덱스로 cnt배열을 찾는다. 각 문자열에 대해서 다음이 수행된다.
//- 5-1. 각 인덱스에 해당하는 cnt 값 중 큰 수는 합집합의 갯수에 추가한다. 
//- 5-2. 각 인덱스에 해당하는 cnt 값 중 작은 수는 교집합의 갯수에 추가한다.
//- 6. 퍼센티지에 따른 값을 리턴한다.
//- 6-1. union이 0인 경우 확률을 1로 정했으므로 65536을 리턴한다.
//- 6-2. 교집합 / 합집합 * 65536의 값을 리턴한다(소숫점 이하 버림).

#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    for (int i = 0; i < str2.length(); i++) str2[i] = toupper(str2[i]);

    int m_index1 = 1;            // 1 ~ 마지막 + 1
    unordered_map<string, int> m;
    int cnt1[2000];
    int cnt2[2000];
    for (int i = 0; i < 2000; i++) {
        cnt1[i] = 0;
        cnt2[i] = 0;
    }

    string temp;
    for (int i = 1; i < str1.length(); i++) {
        temp = str1.substr(i - 1, 2);
        for (int i = 0; i < temp.length(); i++) temp[i] = toupper(temp[i]);
        if (temp[0] < 'A' || temp[0] > 'Z' || temp[1] < 'A' || temp[1] > 'Z') continue;
        if (m.count(temp) == 0) {
            m.insert(make_pair(temp, m_index1));
            cnt1[m_index1] = 1;
            m_index1++;
        }
        else {
            cnt1[m[temp]] += 1;
        }
    }

    int m_index2 = m_index1;       // 마지막 + 1 ~
    for (int i = 1; i < str2.length(); i++) {
        temp = str2.substr(i - 1, 2);
        for (int i = 0; i < temp.length(); i++) temp[i] = toupper(temp[i]);
        if (temp[0] < 'A' || temp[0] > 'Z' || temp[1] < 'A' || temp[1] > 'Z') continue;
        if (m.count(temp) == 0) {
            m.insert(make_pair(temp, m_index2));
            cnt2[m_index2] = 1;
            m_index2++;
        }
        else {
            cnt2[m[temp]] += 1;
        }
    }

    int union_cnt = 0;
    int intersection_cnt = 0;
    for (int id = 1; id < m_index1; id++) {
        union_cnt += max(cnt1[id], cnt2[id]);
        intersection_cnt += min(cnt1[id], cnt2[id]);
    }
    for (int id = m_index1; id < m_index2; id++) {
        union_cnt += cnt2[id];
    }
    
    /*cout << m_index1 << ", " << m_index2 << endl;
    cout << union_cnt << ", " << intersection_cnt << endl;*/

    if (union_cnt == 0) return 65536;

    double result = (double)intersection_cnt / union_cnt;
    answer = result * 65536;

    return answer;
}

//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    /*string str1 = "FRANCE";
//    string str2 = "french";*/
//    string str1 = "aa1+aa2";
//    string str2 = "AAAA12";
//
//    cout << solution(str1, str2);
//
//    return 0;
//}