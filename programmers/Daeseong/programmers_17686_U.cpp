//Solution
//- 문자열 split과 priority queue를 사용하면 쉽게 풀 수 있다.
//- 1. 주어진 문자열을 문자, 숫자, [문자] 순서로 잘라낸다. 각각 HEAD, NUMBER, TAIL이라 한다.
//- 2. 잘라낸 문자열을 정렬한다. (prioriry queue 사용)
//- 2-1. 1순위, HEAD(문자열)의 오름차순
//- 2-2. 2순위, NUMBER(문자열)의 오름차순
//- 2-3. 3순위, index의 오름차순 (1, 2순위가 같을 때, 순서를 유지한다.)
//- 3. 2의 순서대로 문자열 순서를 변경한다.

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
        if (a.number == b.number) return a.index > b.index; // 인덱스 오름차순
        else return a.number > b.number;                    // 숫자 오름차순
    }
    else return a.head > b.head;                            // 문자 오름차순
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