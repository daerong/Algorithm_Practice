//Solution
//- ���ڿ��� �����ϰ� �¿츦 ���Ͽ� ���� �� �ִ�.
//- 1-1. �� �հ� �� ���� ��� ������ ���Ѵ�.
//- 1-2. �߰��� ��� ������ ���Ѵ�.
//- 2. ���ڿ� �񱳴� �տ������� ���ڸ��� �����ϸ� "��ġ ����"�� ������ ���� �����Ѵ�.
//- 2-1. ���� ��� "��ġ ����"�� 1 ������Ų��.
//- 2-2. �ٸ� ��� "��ġ ����"�� 1 ������Ų ��, �񱳸� �����Ѵ�. (���� ���ڿ��� ������ �ѱ��ڸ� �߰��ؾ� ��)
//- 2-3. ���ڿ� ���̰� ���� ���, �񱳸� �����Ѵ�. (��� ���ڿ��� ���� ���ڿ����� ª�� ���)
//- 3. 2���� ���� "��ġ ����" �� ū ���� answer�� ���Ѵ�.

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