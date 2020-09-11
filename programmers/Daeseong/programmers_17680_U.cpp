//Solution
//- vector�� ����� cache�� �����Ͽ���.
//- Ǯ�̰����� ������ ����.
//- 1. ���ڿ��� �빮�ڷ� ��ȯ.
//- 2-1. ó�� ������ ���ڿ��� ���, ������ �����Ѵ�.
//- 2-1-1. ���ڿ��� �ؽøʿ� ��� <���ڿ�, �ε���>
//- 2-1-2. ĳ�ð� ������ ���, ���� ���� ���� ������ �����ϰ� ĳ�ÿ� �߰�.
//- 2-1-3. ĳ�ÿ� ������ ������ ĳ�ÿ� �߰��Ѵ�.
//- 2-1-4. answer�� 5 ������Ų��.
//- 2-2. ���ڿ��� �̹� ������ ���, ������ �����Ѵ�.
//- 2-2-1. ĳ�� �ȿ� ���ڿ��� �ִ� ���
//- 2-2-1-1. �ش� �ε����� ��ġ�� ã�� �ش� ��ġ�� ���и� �����Ѵ�. ���� ĳ�ÿ� �ٽ� �߰��Ѵ�.
//- 2-2-1-2. answer�� 1 ������Ų��.
//- 2-2-2. ĳ�� �ȿ� ���ڿ��� ���� ���
//- 2-2-2-1. ĳ�ð� ������ ���, ���� ���� ���� ������ �����ϰ� ĳ�ÿ� �߰�.
//- 2-2-2-2. ĳ�ÿ� ������ ������ ĳ�ÿ� �߰��Ѵ�.
//- 2-2-2-3. answer�� 5 ������Ų��.


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