//Solution
//- 주어진 조건대로 수행하여 "올바른 괄호 문자열"을 완성하는 문제.
//- 다음에 유의하여 구현하자.
//- 1. 4-4.조건에 해당하는 "나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다"의 의미는
//- 1.1. 문자열의 순서가 뒤바뀌는 것이 아닌
//- 1.2. '(' -> ')', ')' -> '('로 바뀌는 것이다.
//- 풀이과정은 다음과 같다.
//- 1. 재귀적으로 string을 구해야하므로 p를 u와 v로 나누는 divide()함수를 만든다.
//- 2. "균형잡힌 괄호 문자열"에 해당하는 최소길이의 u를 구한다. (p = u + v 형태)
//- 3. p를 u와 v로 나눈다.
//- 4. p에 대해 "올바른 괄호 문자열" 여부를 확인하고 결과에 따라 다음을 수행한다.
//- 4.1. "올바른 괄호 문자열"인 경우
//- 4.1.1. v에 대해 1.부터 수행한 뒤, u + v를 return한다.
//- 4.2. "올바른 괄호 문자열"이 아닌 경우
//- 4.2.1. u의 앞뒤 문자 하나씩을 제거한 뒤, 괄호의 방향을 바꾼다.
//- 4.2.2. v에 대해 1.부터 수행한다.
//- 4.2.3. 다음을 return 한다. -> "(" + 4.2.2.에서 구한 v + ")" + 4.2.1.에서 구한 u

#include <string>
#include <vector>

using namespace std;

int find_locate(string& target) {
    int cnt = 0;
    int i = 0;
    do {
        if (target[i] == '(') cnt++;
        else cnt--;
        i++;
    } while (cnt != 0 && i < target.length());

    return i;
}

bool is_correct(string& target) {
    int cnt = 0;
    for (int i = 0; i < target.length(); i++) {
        if (target[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }

    return true;
}

void mirrored(string& target) {
    for (int i = target.length() - 1; i >= 0; i--) {
        if (target[i] == '(') target[i] = ')';
        else target[i] = '(';
    }
}

string divide(string& p) {
    if (p.length() == 0) return p;
    int locate = find_locate(p);
    string u = p.substr(0, locate);
    string v = p.substr(locate);

    if (is_correct(u)) {
        v = divide(v);
        return u + v;
    }
    else {
        u = p.substr(1, u.length() - 2);
        v = divide(v);
        mirrored(u);
        return "(" + v + ")" + u;
    }
}

string solution(string p) {
    return divide(p);
}