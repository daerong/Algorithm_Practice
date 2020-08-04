//Solution
//- Using bfs
//- 1. 폭탄 주위의 map에 +1을 더한다. 폭탄에는 방문 체크를 한다.
//- 2. 다음의 룰대로 bfs 진행
//- 2-1. 0을 만나면 queue에 넣는다.
//- 2-2. queue에서 하나를 빼고 해당 공간에 방문체크를 한다.
//- 2-3. 0일때, 주변 미방문 숫자를 queue에 넣는다.
//- 2-4. 2-2~2-3을 반복하고 종료 시에는 answer을 1 더한다.
//- 3. 방문하지 않은 셀의 갯수를 더한다.

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    private static int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    private static int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++){
            int answer = 0;
            int N = Integer.parseInt(br.readLine());
            int[][] map = new int[N][N];
            boolean[][] visited = new boolean[N][N];

            for(int y = 0; y < N; y++){
                String str = br.readLine();
                for(int x = 0; x < N; x++){
                    if(str.charAt(x) == '*'){
                        visited[y][x] = true;
                        for(int dir = 0; dir < 8; dir++){
                            int nx = x + dx[dir];
                            if(nx < 0 || nx >=N) continue;
                            int ny = y + dy[dir];
                            if(ny < 0 || ny >=N) continue;
                            map[ny][nx] += 1;
                        }
                    }
                }
            }

            Queue<com.company.Solution.LOCATE> locate = new LinkedList<>();

            for(int y = 0; y < N; y++){
                for(int x = 0; x < N; x++){
                    if(visited[y][x]) continue;
                    if(map[y][x] != 0) continue;
                    locate.offer(new com.company.Solution.LOCATE(x, y));
                    while (!locate.isEmpty()){
                        com.company.Solution.LOCATE temp = locate.poll();
                        if(visited[temp.y][temp.x]) continue;
                        visited[temp.y][temp.x] = true;
                        if(map[temp.y][temp.x] != 0) continue;
                        for(int dir = 0; dir < 8; dir++){
                            int nx = temp.x + dx[dir];
                            if(nx < 0 || nx >=N) continue;
                            int ny = temp.y + dy[dir];
                            if(ny < 0 || ny >=N) continue;
                            locate.offer(new com.company.Solution.LOCATE(nx, ny));
                        }
                    }

                    answer += 1;
                }
            }

            for(int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if(!visited[y][x]) answer += 1;
                }
            }

            System.out.println("#" + t + " " + answer);
        }
    }

    private static class LOCATE {
        int x;
        int y;

        LOCATE(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}