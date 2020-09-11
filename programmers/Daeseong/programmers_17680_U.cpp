//Solution
//- vector을 사용해 cache를 구현하였다.
//- 풀이과정은 다음과 같다.
//- 1. 문자열을 대문자로 변환.
//- 2-1. 처음 등장한 문자열의 경우, 다음을 실행한다.
//- 2-1-1. 문자열을 해시맵에 등록 <문자열, 인덱스>
//- 2-1-2. 캐시가 가득찬 경우, 가장 먼저 들어온 성분을 제거하고 캐시에 추가.
//- 2-1-3. 캐시에 공간이 있으면 캐시에 추가한다.
//- 2-1-4. answer을 5 증가시킨다.
//- 2-2. 문자열이 이미 등장한 경우, 다음을 실행한다.
//- 2-2-1. 캐시 안에 문자열이 있는 경우
//- 2-2-1-1. 해당 인덱스의 위치를 찾아 해당 위치의 성분를 제거한다. 이후 캐시에 다시 추가한다.
//- 2-2-1-2. answer을 1 증가시킨다.
//- 2-2-2. 캐시 안에 문자열이 없는 경우
//- 2-2-2-1. 캐시가 가득찬 경우, 가장 먼저 들어온 성분을 제거하고 캐시에 추가.
//- 2-2-2-2. 캐시에 공간이 있으면 캐시에 추가한다.
//- 2-2-2-3. answer을 5 증가시킨다.


#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return cities.size() * 5;
    int answer = 0;

    unordered_map<string, int> m;
    int m_index = 0;
    vector<int> vec;

    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].length(); j++) {
            cities[i][j] = toupper(cities[i][j]);
        }

        if (m.count(cities[i]) == 0) {
            m.emplace(cities[i], m_index);
            
            if (vec.size() == cacheSize) {
                vec.erase(vec.begin());
                vec.push_back(m_index);
            }
            else vec.push_back(m_index);

            m_index++;

            answer += 5;
        }
        else {
            int index = m[cities[i]];
            if (find(vec.begin(), vec.end(), index) == vec.end()) {

                if (vec.size() == cacheSize) {
                    vec.erase(vec.begin());
                    vec.push_back(index);
                }
                else vec.push_back(index);

                answer += 5;
            }
            else {
                int locate = distance(vec.begin(), find(vec.begin(), vec.end(), index));

                vec.erase(vec.begin() + locate);
                vec.push_back(index);

                answer += 1;
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
//    int cacheSize = 3;
//    vector<string> cities;
//    cities.push_back("Jejs");
//    cities.push_back("Pangyo");
//    cities.push_back("Seoul");
//    cities.push_back("NewYork");
//    cities.push_back("LA");
//    cities.push_back("Jeju");
//    cities.push_back("Pangyo");
//    cities.push_back("Seoul");
//    cities.push_back("NewYork");
//    cities.push_back("LA");
//
//    cout << solution(cacheSize, cities);
//
//    return 0;
//}