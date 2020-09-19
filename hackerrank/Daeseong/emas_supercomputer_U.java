import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the twoPluses function below.
    static int twoPluses(String[] grid) {
        int y_max = grid.length;
        int x_max = grid[0].length();

        int[] dx = {0, 1, 0, -1};
        int[] dy = {-1, 0, 1, 0};

        boolean[][] visited = new boolean[y_max][x_max];
        char[][] map = new char[y_max][];
        for(int y = 0; y < y_max; y++) map[y] = grid[y].toCharArray();

        PriorityQueue<UDS> pq = new PriorityQueue<UDS>();

        for(int y = 0; y < y_max; y++) {
            for (int x = 0; x < x_max; x++) {
                if (map[y][x] == 'G') {
                    boolean is_blocked = false;
                    int len = 1;
                    while (!is_blocked) {
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = x + dx[dir] * len;
                            int ny = y + dy[dir] * len;
                            if (nx < 0 || nx >= x_max || ny < 0 || ny >= y_max) {
                                is_blocked = true;
                                break;
                            }
                            if (map[ny][nx] == 'B') {
                                is_blocked = true;
                                break;
                            }
                        }
                        if (is_blocked) break;
                        len++;
                    }

                    pq.offer(new UDS(x, y, len - 1));
                }
            }
        }

        PriorityQueue<Integer> answer_pq = new PriorityQueue<>();

        while(!pq.isEmpty()){
            UDS temp = pq.poll();
            if(temp.len == 1) break;

            PriorityQueue<UDS> sub_pq = pq;
            System.out.println("a");
            Arrays.fill(visited, false);

            int answer = 1;
            int answer_cnt = 0;

            while(!sub_pq.isEmpty()){
                UDS sub_temp = sub_pq.poll();
                if(visited[sub_temp.y][sub_temp.x]) continue;

                boolean is_visited = false;
                for(int l = 1; l <= sub_temp.len; l++){
                    for(int dir = 0; dir < 4; dir++){
                        int nx = sub_temp.x + dx[dir] * l;
                        int ny = sub_temp.y + dy[dir] * l;
                        if(visited[ny][nx]) {
                            is_visited = true;
                            break;
                        }
                    }
                    if(is_visited) break;
                }
                if(is_visited) continue;

                visited[sub_temp.y][sub_temp.x] = true;
                for(int l = 1; l <= sub_temp.len; l++) {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = sub_temp.x + dx[dir] * l;
                        int ny = sub_temp.y + dy[dir] * l;
                        visited[ny][nx] = true;
                    }
                }

                answer_cnt++;
                answer *= 1 + sub_temp.len * 4;
                if(answer_cnt == 2) break;
            }

            answer_pq.offer(answer);
        }

        return answer_pq.size();
    }

    private static class UDS implements Comparable<UDS>{
        int x;
        int y;
        int len;

        UDS(int x, int y, int len){
            this.x = x;
            this.y = y;
            this.len = len;
        }

        @Override
        public int compareTo(UDS o) {
            if(this.len < o.len) return 1;
            else if(this.len > o.len) return -1;
            else return 0;
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
//        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        String[] grid = new String[n];

        for (int i = 0; i < n; i++) {
            String gridItem = scanner.nextLine();
            grid[i] = gridItem;
        }

        int result = twoPluses(grid);

//        bufferedWriter.write(String.valueOf(result));
//        bufferedWriter.newLine();
//
//        bufferedWriter.close();

        scanner.close();
    }
}