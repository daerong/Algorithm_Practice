//Solution
//- Using Hashmap.
//- 체스말 퀸의 이동가능 위치의 경우의 수를 구하는 문제, 적 기물을 잡아선 안된다.
//- 8 방향 재귀함수로 표현가능하지만 함수 하나로 처리하기 위해 반복문을 사용했다.
//- 다음의 주의사항에 유의하면 쉽게 답을 구할 수 있다.
//- 1. 2차원 배열 사용 시, 공간복잡도가 크게 증가한다. 따라서 해시맵을 사용했다.
//- 2. y * n + x를 사용하면 0 < location < 10^10으로 int 범위를 벗어날 수 있다. 고로 long을 사용한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the queensAttack function below.
    static int queensAttack(int n, int k, int r_q, int c_q, int[][] obstacles) {
        int answer = 0;
        long ln = (long) n;
        HashMap<Long, Integer> m = new HashMap<>();
//        int[][] map = new int[n + 1][n + 1];
        int[] dx = {1, 1, 1, 0, -1, -1, -1, 0};
        int[] dy = {-1, 0, 1, 1, 1, 0, -1, -1};

        for(int i = 0; i < k; i++){
            m.put((long) obstacles[i][0] * ln + (long) obstacles[i][1], 1);
//            map[obstacles[i][0]][obstacles[i][1]] = 1;
        }

        for(int dir = 0; dir < 8; dir++){
            long nx = (long)c_q;
            long ny = (long)r_q;
            while (true){
                nx += dx[dir];
                ny += dy[dir];
                if(nx <= 0 || nx > n || ny <= 0 || ny > n) break;
                if(m.containsKey(ny * ln + nx)) break;
//                if(map[ny][nx] == 1) break;
                answer++;
            }
        }

        return answer;
    }



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        String[] r_qC_q = scanner.nextLine().split(" ");

        int r_q = Integer.parseInt(r_qC_q[0]);

        int c_q = Integer.parseInt(r_qC_q[1]);

        int[][] obstacles = new int[k][2];

        for (int i = 0; i < k; i++) {
            String[] obstaclesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int obstaclesItem = Integer.parseInt(obstaclesRowItems[j]);
                obstacles[i][j] = obstaclesItem;
            }
        }

        int result = queensAttack(n, k, r_q, c_q, obstacles);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
