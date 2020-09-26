//Solution
//- Using bitmask.
//- 접근방법을 떠올리지 못해 상당히 고전한 문제.
//- 1. 후보키를 찾는다. (중복된 성분이 없어야함)
//- 1-1. 후보키의 갯수 별로 다음을 수행한다. (1부터 오름차순)
//- 1-1-1. 1부터 n(2^column의 갯수)미만의 수 까지에 대해 다음을 수행한다.
//- 1-1-1-1. 1-1-1을 이루는 숫자를 2진법 변환 후 1의 갯수가 1-1의 갯수와 일치할 경우 다음을 실행한다.
//- 1-1-1-2. 각각의 column안에 있는 string을 모두 더한다.
//- 1-1-1-3. 더해진 string이 map안에 있는 지 확인한다.
//- 1-1-1-3-1. 있을 경우, 후보키의 조건 중 유일성에 위배되므로 후보키를 이룰 수 없다.
//- 1-1-1-3-2. 없을 경우, map에 더해진 string을 추가한다.
//- 1-1-1-4. 모든 성분에 대해 유일성이 보장되는 경우 1-1-1의 숫자를 result_set 벡터에 추가한다.
//- 1-2. result_set 벡터(이진법으로 나타낸 후보키)에 대해 최소성을 판단한다.
//- 1-2-1. result_set의 마지막 원소부터 다음을 실행한다.
//- 1-2-1-1. 1-2-1.의 원소 앞에 있는 모든 원소에 대해 부분집합 관계를 갖는 지 확인한다.
//            - (result_set[i] | result_set[j]) == result_set[i]인 경우, 부분집합임을 알 수 있다.
//- 1-1-1-2. 부분집합인 경우 1-2-1. 원소를 제거한다.
//- 1-3. 최종적으로 result_set에 남아있는 성분은 유일성과 최소성을 만족하는 후보키이므로 갯수를 리턴한다.

#include <iostream>
// Code start

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

#define C_MAX 8
#define R_MAX 20

int get_volume(int n) {
    int cnt = 0;
    for (int locate = 0; locate < 8; locate++) {
        if (n & (1 << locate)) cnt++;
    }
    return cnt;
}

int solution(vector<vector<string>> relation) {
    int row_max = relation.size();
    int col_max = relation[0].size();
    int check_max = pow(2, col_max);

    unordered_map<string, int> m;
    int m_index = 0;
    vector<int> result_set;

    int each_vol[256];
    for (int n = 1; n < check_max; n++) {
        each_vol[n] = get_volume(n);
    }

    // 1. 후보키를 찾는다. (중복된 성분이 없어야함)
    for (int volume = 1; volume <= col_max; volume++) {
        // 1-1. 후보키의 갯수 별로 다음을 수행한다. (1부터 오름차순)
        for (int n = 1; n < check_max; n++) {
            // 1-1-1. 1부터 n(2^column의 갯수)미만의 수 까지에 대해 다음을 수행한다.
            if (each_vol[n] != volume) continue;    
            // 1-1-1-1. 1-1-1을 이루는 숫자를 2진법 변환 후 1의 갯수가 1-1의 갯수와 일치할 경우 다음을 실행한다.
            for (int row = 0; row < row_max; row++) {
                string temp = "";
                for (int col = 0; col < col_max; col++) {
                    // 1-1-1-2. 각각의 column안에 있는 string을 모두 더한다.
                    if (n & (1 << col)) temp += relation[row][col];
                }
                // 1-1-1-3. 더해진 string이 map안에 있는 지 확인한다.
                if (m.count(temp) == 1) {
                    // 1-1-1-3-1. 있을 경우, 후보키의 조건 중 유일성에 위배되므로 후보키를 이룰 수 없다.
                    m.clear();
                    m_index = 0;
                    break;
                }
                else {
                    // 1-1-1-3-2. 없을 경우, map에 더해진 string을 추가한다.
                    m.insert({ temp, m_index++ });
                }
            }

            if (!m.empty()) {
                // 1-1-1-4. 모든 성분에 대해 유일성이 보장되는 경우 1-1-1의 숫자를 result_set 벡터에 추가한다.
                result_set.push_back(n);
                m.clear();
                m_index = 0;
            }
        }
    }

    // 1-2. result_set 벡터(이진법으로 나타낸 후보키)에 대해 최소성을 판단한다.
    for (int i = result_set.size() - 1; i >= 0; i--) {
        // 1-2-1. result_set의 마지막 원소부터 다음을 실행한다.
        for (int j = i - 1; j >= 0; j--) {
            // 1-2-1-1. 1-2-1.의 원소 앞에 있는 모든 원소에 대해 부분집합 관계를 갖는 지 확인한다.
            if ((result_set[i] | result_set[j]) == result_set[i]) {
                // 1-1-1-2. 부분집합인 경우 1-2-1. 원소를 제거한다.
                result_set.erase(result_set.begin() + i);
                break;
            }
        }
    }

    // 1-3. 최종적으로 result_set에 남아있는 성분은 유일성과 최소성을 만족하는 후보키이므로 갯수를 리턴한다.
    return result_set.size();
}

// Code end
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<string>> relation;
    relation.push_back({ "100", "ryan", "music", "2" });
    relation.push_back({ "200", "apeach", "math", "2" });
    relation.push_back({ "300", "tube", "computer", "3" });
    relation.push_back({ "400", "con", "computer", "4" });
    relation.push_back({ "500", "muzi", "music", "3" });
    relation.push_back({ "600", "apeach", "music", "2" });

    cout << solution(relation);

    return 0;
}