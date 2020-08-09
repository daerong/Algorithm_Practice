//Solution
//    - Using Hashmap.
//    - 아래의 방법을 통해 해시맵으로 다음위치를 쉽게 얻어낼 수 있다.
//    - 1. Hashmap이 비어있는 경우, Hashmap을 채우고 그 다음 번호를 가르키게 한다.
//    - 2. Hashmap이 차있는 경우, 해시맵이 가르키는 위치를 찾는다.
//    - 3. 2번을 여러번 반복한 경우, 과정에 있는 Hashmap에 최종 위치를 기록하면 재귀반복을 줄일 수 있다.
//          - 예를들면 1-2-3-4-5 순으로 재귀를 반복한 경우, 1, 2, 3, 4가 모두 5를 가르키면 더 빠른 수행이 가능하다.

package com.company;

import java.util.HashMap;

class Solution {
    HashMap<Long, Long> m = new HashMap<>();

    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];

        for(int i = 0; i < room_number.length; i++){
            long room_index = room_number[i];

            answer[i] = find(room_index);
        }

        return answer;
    }

    private long find(Long target) {
        if(!m.containsKey(target)){
            // 1. Hashmap이 비어있는 경우, Hashmap을 채우고 그 다음 번호를 가르키게 한다.
            m.put(target, target + 1);
            return target;
        }else{
            // 2. Hashmap이 차있는 경우, 해시맵이 가르키는 위치를 찾는다.
            m.put(target, find(m.get(target)));     // 3. 2번을 여러번 반복한 경우, 과정에 있는 Hashmap에 최종 위치를 기록하면 재귀반복을 줄일 수 있다.
            return m.get(target);
        }
    }
}