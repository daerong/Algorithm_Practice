//Solution
//- Using Hashmap.
//- �ش� ������ ������ ���� Ǯ �� �ִ�.
//- 1. �־��� ���ڿ��� ���� 2 ������ sub string���� �ٲ۴�.
//- 2. �������� ���ڿ��� �׷찣 �񱳸� �����Ͽ� �����հ� �������� ���Ұ����� ��´�.
//- 3. ������ / ������ * 65536�� ���� �����Ѵ�(�Ҽ��� ���� ����).
//- ������ Ǯ���� ������ ������ ����.
//- 1. substring���� 1�� ���ڿ��� 2 ���̷� �ڸ���.
//- 2. Hashmap�� <���ڿ�, �ε���> ���·� �����Ѵ�. 
//- 2-1. 1�� �������� ���� ���ڿ��� �߻��� �� �����Ƿ� Hashmap���� Ȯ���Ѵ�.
//- 2-2. ���� ���ڿ��� ���� count�� ������ cnt �迭�� �߰��� �����Ѵ�.
//- 3. substring���� 2�� ���ڿ��� 2 ���̷� �ڸ���.
//- 4. Hashmap�� <���ڿ�, �ε���> ���·� �����Ѵ�. ��, �ε����� 1���� �����ϰ� ����Ѵ�.
//- 4-1. 2�� ���ڿ������� 1������ �߻����� ���� ���ڿ��� �߻��� �� �ִ�. �� ��� 1�� ������ �ε����� ����Ͽ� �����Ѵ�.
//- 5. 1�� ���ڿ��� ���� �ε����� cnt�迭�� ã�´�. �� ���ڿ��� ���ؼ� ������ ����ȴ�.
//- 5-1. �� �ε����� �ش��ϴ� cnt �� �� ū ���� �������� ������ �߰��Ѵ�. 
//- 5-2. �� �ε����� �ش��ϴ� cnt �� �� ���� ���� �������� ������ �߰��Ѵ�.
//- 6. �ۼ�Ƽ���� ���� ���� �����Ѵ�.
//- 6-1. union�� 0�� ��� Ȯ���� 1�� �������Ƿ� 65536�� �����Ѵ�.
//- 6-2. ������ / ������ * 65536�� ���� �����Ѵ�(�Ҽ��� ���� ����).

#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    for (int i = 0; i < str2.length(); i++) str2[i] = toupper(str2[i]);

    int m_index1 = 1;            // 1 ~ ������ + 1
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

    int m_index2 = m_index1;       // ������ + 1 ~
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