//Solution
//- ���ڿ� split�� priority queue�� ����ϸ� ���� Ǯ �� �ִ�.
//- 1. �־��� ���ڿ��� ����, ����, [����] ������ �߶󳽴�. ���� HEAD, NUMBER, TAIL�̶� �Ѵ�.
//- 2. �߶� ���ڿ��� �����Ѵ�. (prioriry queue ���)
//- 2-1. 1����, HEAD(���ڿ�)�� ��������
//- 2-2. 2����, NUMBER(���ڿ�)�� ��������
//- 2-3. 3����, index�� �������� (1, 2������ ���� ��, ������ �����Ѵ�.)
//- 3. 2�� ������� ���ڿ� ������ �����Ѵ�.

//#include <iostream>
// Code start

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct NAME {
    int index;
    string head;
    int number;
} NAME;

bool operator <(NAME a, NAME b) {
    if (a.head == b.head) {
        if (a.number == b.number) return a.index > b.index; // �ε��� ��������
        else return a.number > b.number;                    // ���� ��������
    }
    else return a.head > b.head;                            // ���� ��������
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    priority_queue<NAME> pq;
    for (int i = 0; i < files.size(); i++) {
        string temp = files[i];
        string head;
        string number;
        int index;
        for (index = 0; index < temp.size(); index++) {
            if (temp[index] >= '0' && temp[index] <= '9') {
                head = temp.substr(0, index);
                temp = temp.substr(index);
                break;
            }

            temp[index] = toupper(temp[index]);
        }
        for (index = 0; index < temp.size(); index++) {
            if (temp[index] < '0' || temp[index] > '9') break;
        }
        number = temp.substr(0, index);

        pq.push({ i, head, stoi(number) });
    }

    NAME temp;
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();

        answer.push_back(files[temp.index]);
    }

    return answer;
}

// Code end
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    vector<string> files;
//    files.push_back("img12.png");
//    files.push_back("img10.png");
//    files.push_back("img02.png");
//    files.push_back("img1.png");
//    files.push_back("IMG01.png");
//    files.push_back("img2.png");
//
//    vector<string> result = solution(files);;
//    for (vector<string>::iterator iter = result.begin(); iter < result.end(); iter++) {
//        cout << *iter << endl;
//    }
//
//
//
//    return 0;
//}