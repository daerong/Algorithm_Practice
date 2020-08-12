//Solution
//- Using priority queue.
//- mix를 수행하면 전체 갯수에서 1이 빠진다.
//- 따라서 이 문제의 해답은 다음과 같이 구할 수 있다.
//- 1. queue 갯수가 1개일 때, -1을 리턴
//- 2. queue에서 가장작은 요소를 가져온다.
//- 2-1. 가장 작은 요소의 값이 K이상인 경우 반복 횟수를 리턴.
//- 2-2. 가장 작은 요소의 값이 K미만인 경우 다음을 수행한다.
//        - queue에서 두번째로 작은 요소를 가져온다.
//        - 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
//        - 섞은 음식의 스코빌 지수를 다시 queue에 넣는다.
//- 3. 1부터 다시 반복한다.

import java.util.PriorityQueue;

class Solution {
    PriorityQueue<Integer> q = new PriorityQueue<>();

    public int solution(int[] scoville, int K) {
        int answer = 0;

        for(int i = 0; i < scoville.length; i++) q.offer(scoville[i]);
        while (!q.isEmpty()){
            int temp = q.poll();
            if(temp >= K) break;
            if(q.isEmpty()) return -1;

            int mix = q.poll();
            mix = mix * 2 + temp;
            q.offer(mix);
            answer++;
        }

        return answer;
    }
}