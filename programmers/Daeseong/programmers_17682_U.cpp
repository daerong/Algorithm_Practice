//Solution
//- 문자열을 잘라내며 원하는 기능을 수행하면 되는 문제.
//- 1. #, * 특수기호를 우선 확인
//- 2. 숫자 뒤에는 무조건 문자가 나오므로 같이 잘라내어 활용한다.

#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    int point = 0;
    int before = 0;
    bool before_star = false;
    bool before_num = true;
    for (int i = 0; i < dartResult.length(); i++) {
        switch (dartResult[i]){
        case '*' :
            if (before_star) {
                answer += point;
                answer += before * 2;
            }
            else {
                answer += point;
                if (before != 0) answer += before;
            }
            before_star = true;
            before_num = false;
            break;
        case '#' :
            point *= -1;
            answer += point * 2;
            before_star = false;
            before_num = false;
            break;

        default:
            if(before_num) before_star = false;
            before_num = true;
            string temp = dartResult.substr(i, 2);
            before = point;
            switch (temp[1]){
            case 'S':
                point = stoi(temp.substr(0, 1));
                answer += point;
                i += 1;
                break;
            case 'D':
                point = pow(stoi(temp.substr(0, 1)), 2);
                answer += point;
                i += 1;
                break;
            case 'T':
                point = pow(stoi(temp.substr(0, 1)), 3);
                answer += point;
                i += 1;
                break;

            default:
                switch (dartResult[i + 2]) {
                case 'S':
                    point = stoi(temp);
                    answer += point;
                    i += 2;
                    break;
                case 'D':
                    point = pow(stoi(temp), 2);
                    answer += point;
                    i += 2;
                    break;
                case 'T':
                    point = pow(stoi(temp), 3);
                    answer += point;
                    i += 2;
                    break;
                }
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
//    cout << solution("1S2D*3T") << "\n";
//    cout << solution("1D2S#10S") << "\n";
//    cout << solution("1D2S0T") << "\n";
//    cout << solution("1S*2T*3S") << "\n";
//    cout << solution("1D#2S*3S") << "\n";
//    cout << solution("1T2D3D#") << "\n";
//    cout << solution("1D2S3T*") << "\n";
//
//    return 0;
//}