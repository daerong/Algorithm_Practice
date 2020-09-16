//Solution
//- 문자열을 정렬하고 좌우를 비교하여 얻을 수 있다.
//- 1-1. 맨 앞과 맨 뒤의 경우 한쪽을 비교한다.
//- 1-2. 중간의 경우 양쪽을 비교한다.
//- 2. 문자열 비교는 앞에서부터 한자리씩 진행하며 "일치 길이"를 다음과 같이 변경한다.
//- 2-1. 같은 경우 "일치 길이"를 1 증가시킨다.
//- 2-2. 다른 경우 "일치 길이"를 1 증가시킨 후, 비교를 종료한다. (동일 문자열이 있으면 한글자를 추가해야 함)
//- 2-3. 문자열 길이가 끝난 경우, 비교를 종료한다. (대상 문자열이 비교할 문자열보다 짧은 경우)
//- 3. 2에서 얻은 "일치 길이" 중 큰 값을 answer에 더한다.

//#include <iostream>
// Code start

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;

    sort(words.begin(), words.end());
    unordered_map<string, int> m;

    for (int m_id = 0; m_id < words.size(); m_id++) {
        if (m_id == 0) {
            int same_len_r = 0;
            for (int s_id = 0; s_id < words[m_id].length(); s_id++) {
                if (s_id >= words[m_id + 1].length()) {
                    same_len_r++;
                    break;
                }
                //cout << words[m_id][s_id] << ", " << words[m_id + 1][s_id] << endl;
                if (words[m_id][s_id] != words[m_id + 1][s_id]) {
                    same_len_r++;
                    break;
                }
                same_len_r++;
            }

            answer += same_len_r;
        }
        else if (m_id == words.size() - 1) {
            int same_len_l = 0;
            for (int s_id = 0; s_id < words[m_id].length(); s_id++) {
                if (s_id >= words[m_id - 1].length()) {
                    same_len_l++;
                    break;
                }
                //cout << words[m_id][s_id] << ", " << words[m_id - 1][s_id] << endl;
                if (words[m_id][s_id] != words[m_id - 1][s_id]) {
                    same_len_l++;
                    break;
                }
                same_len_l++;
            }

            answer += same_len_l;
        }
        else {
            int same_len_l = 0;
            int same_len_r = 0;
            for (int s_id = 0; s_id < words[m_id].length(); s_id++) {
                if (s_id >= words[m_id - 1].length()) {
                    same_len_l++;
                    break;
                }
                //cout << words[m_id][s_id] << ", " << words[m_id - 1][s_id] << endl;
                if (words[m_id][s_id] != words[m_id - 1][s_id]) {
                    same_len_l++;
                    break;
                }
                same_len_l++;
            }
            for (int s_id = 0; s_id < words[m_id].length(); s_id++) {
                if (s_id >= words[m_id + 1].length()) {
                    same_len_r++;
                    break;
                }
                //cout << words[m_id][s_id] << ", " << words[m_id + 1][s_id] << endl;
                if (words[m_id][s_id] != words[m_id + 1][s_id]) {
                    same_len_r++;
                    break;
                }
                same_len_r++;
            }

            answer += max(same_len_r, same_len_l);
        }
    }
    return answer;
}

// Code end
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    vector<string> words;
//    words.push_back("word");
//    words.push_back("war");
//    words.push_back("warrior");
//    words.push_back("world");
//
//    cout << solution(words);
//
//    return 0;
//}