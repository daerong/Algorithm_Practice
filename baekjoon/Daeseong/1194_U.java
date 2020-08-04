//Solution
//- Using bfs.
//- 키의 유무에 따라 통과여부가 달라질 수 있다. 따라서 키의 상태를 가지고 bfs탐색을 진행한다.
//- 키의 갯수는 6개 총 T, F로 키 보유 상황을 2진번으로 나타내면 0~63의 범위 안에서 표현 가능하다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static char[][] map;
    private static boolean[][][] visited;
    private static int[] dx = {0, 0, 1, -1};
    private static int[] dy = {-1, 1, 0, 0};
    private static int N;
    private static int M;
    private static final char keyStart = 'a';
    private static final char keyEnd = 'f';
    private static final char doorStart = 'A';
    private static final char doorEnd = 'F';

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   // nextToken()
        StringTokenizer st = new StringTokenizer(br.readLine());                    // 공백 문자 제외

        N = Integer.parseInt(st.nextToken());           // 공백 구분자로 입력, Scanner보다 빠르다.
        M = Integer.parseInt(st.nextToken());

        map = new char[N][M];
        visited = new boolean[N][M][64];

        int startX = 0;
        int startY = 0;
        for(int y = 0; y < N; y++){
            map[y] = br.readLine().toCharArray();

            for(int x = 0; x < M; x++){
                if(map[y][x] == '0'){
                    startX = x;
                    startY = y;
                }
            }
        }

        bfs(startX, startY);
    }

    private static void bfs(int x, int y) {
        Queue<UDS> q = new LinkedList<>();

        q.add(new com.company.Solution.UDS(x, y, 0, 0));
        visited[y][x][0] = true;

        while(!q.isEmpty()){
            com.company.Solution.UDS temp = q.poll();            //

            if(map[temp.y][temp.x] == '1'){
                System.out.println(temp.cnt);
                return;
            }

            for(int dir = 0; dir < 4; dir++){
                int nx = temp.x + dx[dir];
                int ny = temp.y + dy[dir];

                if(nx < 0 || nx >= M) continue;
                if(ny < 0 || ny >= N) continue;
                if(map[ny][nx] == '#') continue;
                if(visited[ny][nx][temp.key]) continue;

                if(map[ny][nx] >= keyStart && map[ny][nx] <= keyEnd){
                    int newKey = (1 << (map[ny][nx] - 'a')) | temp.key;

                    if(!visited[ny][nx][newKey]){
                        visited[ny][nx][newKey] = true;
                        visited[ny][nx][temp.key] = true;
                        q.add(new com.company.Solution.UDS(nx, ny, temp.cnt + 1, newKey));
                    }
                }else if(map[ny][nx] >= doorStart && map[ny][nx] <= doorEnd){
                    int doorCheck = (1 << (map[ny][nx] - 'A')) & temp.key;
                    if(doorCheck > 0){
                        visited[ny][nx][temp.key] = true;
                        q.add(new com.company.Solution.UDS(nx, ny, temp.cnt + 1, temp.key));
                    }
                }else{
                    visited[ny][nx][temp.key] = true;
                    q.add(new com.company.Solution.UDS(nx, ny, temp.cnt + 1, temp.key));
                }
            }
        }

        System.out.println(-1);
    }

    private static class UDS {
        int x;
        int y;
        int cnt;
        int key;

        public UDS(int x, int y, int cnt, int key) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.key = key;
        }
    }
}