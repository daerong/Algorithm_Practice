//Solution
//- Hashmap�� ����ϸ� ���� Ǯ �� ������ ������ �����Ѵ�.
//- 1. "A"�� �ε����� 1�̴�. 
//- 2. "A" ~ "Z" ������ �켱 mapping�Ѵ�.
//- 3. �ִ������ ���ڿ��� �켱���� Ȯ���Ѵ�.
//- 4. �˻� ���ڿ��� �߰ߵǸ� ������ �����Ѵ�.
//- 4-1. answer�� index�� �߰��Ѵ�.
//- 4-2. �˻����ڿ� + �ٷ� ���� ���ڸ� map�� �߰��Ѵ�.
//- 4-2-1. 4-2���� �ٷ� ���� ���ڰ� ���� ��� �����Ѵ�.
//- 4-3. 4-2���� �߰��� ���ڿ��� ���̰� ���� �ִ밪���� Ŭ ��� ������Ʈ�Ѵ�.
//- 4-4. 4���� �˻��� ���ڿ��� �����Ѵ�.

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
                //cout << "�����Է� : " << msg.substr(0, len) << endl;
                answer.push_back(m[msg.substr(0, len)]);
                if (msg.length() != len) {
                    //cout << "�����߰� : " << m_index << " : "<< msg.substr(0, len + 1) << endl;
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