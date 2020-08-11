//Solution
//- Using BFS
//- 정석적으로 Queue를 이용했다.
//- visited 배열에서 방문체크를 하며 결과값을 구함.

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;

        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);

        for(int y = 0; y < n; y++){
            if(visited[y]) continue;
            q.offer(y);
            while (!q.isEmpty()){
                int index = q.poll();
                if(visited[index]) continue;
                visited[index] = true;

                for(int x = 0; x < n; x++){
                    if(visited[x]) continue;
                    if(computers[index][x] == 1) q.offer(x);
                }
            }

            answer++;
        }

        return answer;
    }
}