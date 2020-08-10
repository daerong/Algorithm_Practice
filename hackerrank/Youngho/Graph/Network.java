//https://programmers.co.kr/learn/courses/30/lessons/43162?language=java
//try : 2
//비고 : 네트워크 집합의 수는 '노드 수 - 간선 수'로 계산했었다.
//       그러나 Timeout이 너무 많이 발생했고, DFS를 써서 효율성을 높혔다.



/* try 2
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
*/

class Solution
{
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean [] visited = new boolean[n];

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, n, computers, visited);
                answer++;
            }
        }        
        return answer;
    }
    private void dfs(int start, int n, int[][] computers,  boolean [] visited){      
        visited[start] = true;
        for(int i=0; i<n; i++){
            if(start != i && computers[start][i] == 1 && visited[i] == false){
                dfs(i, n, computers, visited);
            }
        }
    }
}
