//https://programmers.co.kr/learn/courses/30/lessons/43162?language=java
//비고 : easy, 디버깅을 하다보니 네트워크의 수는 간선-count였음.


class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        answer = network(n, computers);
        return answer;
    }
    private int network(int n, int[][] arr){
        int count = 0;
        boolean [][]visited = new boolean[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j)
                    continue;
                if(arr[i][j] == 1 && visited[i][j] == false && visited[j][i] == false){
                    count ++;
                    visited[i][j] = true;
                    visited[j][i] = true;
                }
            }
        }
        return n-count;
    }
}
