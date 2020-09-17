//Solution
//- 문제를 읽고 구현하면 쉽게 풀리지만 생각보다 구현할 부분이 많음.
//- 1. 각 숫자별 문자의 길이가 다르기 때문에 나누기 & 모듈러 연산을 사용해 나누는 작업이 필요하다.
//- 2. 11진법~16진법은 숫자 -> 문자 변환이 필요하다.
//- 효율성을 늘리기 위해 다음을 고려할 수 있다.
//- 1. 길이를 먼저 구하고 해당부분을 추가할 필요가 없을 경우 pass.

//#include <iostream>
// Code start

#include <string>
#include <vector>

using namespace std;

char change(int number) {
    switch (number) {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    default: return '-';
    }
}

vector<char> getLength(int number, int type) {
    int temp = number;
    vector<char> vec;
    if (temp == 0) {
        vec.push_back('0');
        return vec;
    }
    while (temp > 0) {
        vec.push_back(change(temp % type));
        temp /= type;
    }

    return vec;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int answer_len = 0;
    int number = 0;
    long long turn = 0;
    vector<char> temp;
    while (answer_len < t) {
        temp = getLength(number++, n);
        while (!temp.empty()) {
            //cout << temp.back();
            if (turn % m == p - 1) {
                answer += temp.back();
                answer_len++;
                if (answer_len == t) break;
            }
            temp.pop_back();
            turn++;
        }
        //cout << endl;
    }

    return answer;
}

// Code end
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n = 16;
//    int t = 16;
//    int m = 2;
//    int p = 1;
//
//    cout << solution(n, t, m, p);
//
//    return 0;
//}