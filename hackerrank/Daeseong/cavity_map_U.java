//Solution
//- 다음과 같은 조건으로 문제를 해결해야한다.
//- 1. 상하좌우 4방향의 값보다 큰 셀을 찾는다.
//- 2. 상하좌우가 없는 셀 즉 외곽의 셀은 제외한다.
//- 문제를 해결하기 위해 다음의 방법을 사용했다.
//- 1. Priority queue를 사용해 각각의 수를 저장한다.
//    - Integer값으로 value * 10000 + y * N + x (value는 셀의 값, N의 최대값은 99)
//- 2. Priority queue를 아래와 같이 순차적으로 확인한다.
//    - 2-1. value 순으로 저장된 Priority queue에서 front 원소를 하나 꺼낸다.
//    - 2-2. 원소에서 value를 제거하고 x, y 성분을 분리한다.
//    - 2-3. 방문 여부를 확인한다. 방문한 경우 2-1로 돌아간다.
//    - 2-4. 방문 체크
//    - 2-5. 상하좌우 4방향에 대해 값 비교를 실행한다.
//        - 2-5-1. 비교할 값보다 큰 경우 비교 대상에 방문체크(해당 셀은 방문할 필요가 없다)
//    - 2-6. 상하좌우 4방향 모든 경우에 대해 2-5-1를 실행했다면 해당 셀을 X표시한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the cavityMap function below.
    static String[] cavityMap(String[] grid) {
        int[] dx = {0, 1, 0, -1};
        int[] dy = {-1, 0, 1, 0};
        int N = grid.length;
        boolean[][] visited = new boolean[N][N];
        char[][] answer = new char[N][N];
        for(int n = 0; n < N; n++){
            answer[n] = grid[n].toCharArray();
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                int num = answer[y][x] - '0';
                pq.offer(10000 * num + y * N + x);
            }
        }

        while (!pq.isEmpty()){
            int temp = pq.poll() % 10000;
            int y = temp / N;
            int x = temp % N;
            if(x == 0 || x == N - 1 || y == 0 || y == N - 1) visited[y][x] = true;
            if(visited[y][x]) continue;
            visited[y][x] = true;

            boolean is_deep = true;
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(answer[y][x] > answer[ny][nx]) visited[ny][nx] = true;
                else is_deep = false;
            }

            if(is_deep) answer[y][x] = 'X';
        }

        for(int y = 0; y < N; y++){
            grid[y] = String.copyValueOf(answer[y]);
        }

        return grid;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String[] grid = new String[n];

        for (int i = 0; i < n; i++) {
            String gridItem = scanner.nextLine();
            grid[i] = gridItem;
        }

        String[] result = cavityMap(grid);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(result[i]);

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}