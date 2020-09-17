//Solution
//- ������ ���� ���������� ���ڿ� �Է¿��� ������ �־���.
//- Ǯ�̰����� ������ ����.
//- 1. ���ڸ� 3���� ������.
//    - ���ڴ� command, user, nickname ���� �������� ������ ������ nickname�� ���� ���� �ִ�.
//    - ���⼭ ���鹮��(' ')�� ã�� ������ ����� �̿��ϴ� �׽�Ʈ���̽����� ���� ���а� ����.
//    - �̸� stringstream ��ü�� �޾� ó���ϴ� ��� ����ƴ�. 
//- 2. ��ɾ ���� ������ �����Ѵ�.
//- 2-1. ��ɾ� == Enter
//- 2-1-1. user�� ó�� ������ ���, map<string, index>�� �ִ´�.
//- 2-1-2. map���� user�� index�� ã�´�.
//- 2-1-3. string �迭�� index��° ���Ҹ� nickname���� ġȯ�Ѵ�.
//- 2-1-4. user�� ���� ��ɾ�(����)�� ť�� �߰��Ѵ�.
//- 2-2. ��ɾ� == Leave
//- 2-2-1. map���� user�� index�� ã�´�.
//- 2-2-2. user�� ���� ��ɾ�(����)�� ť�� �߰��Ѵ�.
//- 2-3. ��ɾ� == Change
//- 2-3-1. map���� user�� index�� ã�´�.
//- 2-3-2. string �迭�� index��° ���Ҹ� nickname���� ġȯ�Ѵ�.
//- 3. ť�� ��ȸ�ϸ� ������ �����Ѵ�.
//- 3-1. ť���� ���Ҹ� �ϳ� ������.
//- 3-2. user�� ã�� index�� �����´�.
//- 3-3. string �迭���� index��° ����(= �����̸�)�� �����´�.
//- 3-4. ť�� ��ɾ�(���� or ����)�� �Ǵ��Ͽ� ������ �����Ѵ�.
//- 3-2-1. if ���� : �����̸� + "���� ���Խ��ϴ�."
//- 3-2-2. if ���� : �����̸� + "���� �������ϴ�."
//- 3-5. 3-4���� ���� ��Ʈ���� ����� �߰��Ѵ�.

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
        if (temp.type) answer.push_back(name[temp.m_id] + "���� ���Խ��ϴ�.");
        else answer.push_back(name[temp.m_id] + "���� �������ϴ�.");
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