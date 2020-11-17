//Solution
//- ���ڿ� ���� ����.
//- �����ؾ� �� ����
//- 1. ���ڿ��� �������� ���� ��, s.length() / 2 + 1�� ����Ѵ�.
//- Ǯ�̰����� ������ ����.
//- 1. �ڸ� ���� len�� ���������� ������Ű�� ������ �����Ѵ�. (���ڿ��� ���ݱ��� ����)
//- 1.1. map�� �� ���ڿ��� �߶� index�� �ο��Ѵ�.
//- 1.2. �߶��� ���ڿ��� ���� index�� vector�� �ִ´�.
//- 1.3. vector�� ���� ������ �����Ѵ�.
//- 1.3.1. �� index�� ���� index�� ������, ������ �����Ѵ�.
//- 1.3.1.1. ���̸� len��ŭ ���ҽ�Ų��.
//- 1.3.1.2. cnt�� 1������Ų��.
//- 1.3.2. �� index�� ���� index�� �ٸ���, ������ �����Ѵ�.
//- 1.3.2.1. cnt�� 2�̻��̸� ������ ���̸�ŭ answer�� ���Ѵ�. (ex> 5�� 1��, 20�� 2��, 101�� 3�� ����) 
//- 1.3.2.2. cnt�� 1�� �����.
//- 2. ���� ���̸� ����Ѵ�.

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