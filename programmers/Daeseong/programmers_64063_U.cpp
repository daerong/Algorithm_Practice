//Solution
//- Using Hashmap.
//- k의 최댓값이 10^12이라 배열을 통한 방문체크에 어려움이 있다. (메모리 초과로 Fail)
//- 아래의 방법을 통해 해시맵으로 다음위치를 쉽게 얻어낼 수 있다.
//- 1. Hashmap이 비어있는 경우, Hashmap을 채우고 그 다음 번호를 가르키게 한다. 
//- 2. Hashmap이 차있는 경우, 해시맵이 가르키는 위치를 찾는다.
//- 3-1. 2에서 찾은 위치가 비어있는 경우, Hashmap을 채우고 그 다음 번호를 가르키게 한다.
//- 3-2. 2번을 여러번 반복한 경우, 과정에 있는 Hashmap에 최종 위치를 기록하면 재귀반복을 줄일 수 있다.
//        - 예를들면 1-2-3-4-5 순으로 재귀를 반복한 경우, 1, 2, 3, 4가 모두 5를 가르키면 더 빠른 수행이 가능하다.
//- 4. 2에서 찾은 위치가 차있는 경우, 현재 위치에서 다시 2를 실행한다.


#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> answer;
unordered_map<long long, long long> m;

long long find(long long target) {
    if (m[target] == 0) {
        // 3-1. 2에서 찾은 위치가 비어있는 경우, Hashmap을 채우고 그 다음 번호를 가르키게 한다.
        answer.emplace_back(target);
        m[target] = target + 1;
        return target + 1;
    }

    // 4. 2에서 찾은 위치가 차있는 경우, 현재 위치에서 다시 2를 실행한다.
    return m[target] = find(m[target]);     // 3-2. 2번을 여러번 반복한 경우, 과정에 있는 Hashmap에 최종 위치를 기록하면 재귀반복을 줄일 수 있다.
}

vector<long long> solution(long long k, vector<long long> room_number) {
    m.reserve(room_number.size() + 1);          // reserve() 메모리 재할당 방지
    answer.reserve(room_number.size());

    long long room_index;
    for (int i = 0; i < room_number.size(); i++) {
        room_index = room_number[i];
        if (m[room_index] == 0) {
            // 1. Hashmap이 비어있는 경우, Hashmap을 채우고 그 다음 번호를 가르키게 한다. 
            answer.emplace_back(room_index);        // 일반적으로 push_back()보다 빠름
            m[room_index] = room_index + 1;
        }
        else {
            // 2. Hashmap이 차있는 경우, 해시맵이 가르키는 위치를 찾는다.
            find(m[room_index]);
        }
    }

    return answer;
}