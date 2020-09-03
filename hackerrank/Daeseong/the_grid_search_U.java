//Solution
//- 배열에서 부분이 일치하는 가를 찾는 문제.
//- 찾을 대상이 되는 배열의 첫번째 원소를 일치시킨 후 나머지 원소를 비교했다.
//- 원본 배열과 찾을 배열의 크기가 둘다 큰 경우, 방문체크를 하면 시간을 단축시킬 수 있다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the gridSearch function below.
    static String gridSearch(String[] G, String[] P) {
        int G_y = G.length;
        int G_x = G[0].length();
        char[][] GM = new char[G_y][G_x];
        for(int y = 0; y < G_y; y++) GM[y] = G[y].toCharArray();
        int P_y = P.length;
        int P_x = P[0].length();
        char[][] PM = new char[P_y][P_x];
        for(int y = 0; y < P_y; y++) PM[y] = P[y].toCharArray();

        for(int y = 0; y < G_y - P_y + 1; y++){
            for(int x = 0; x < G_x - P_x + 1; x++){
                if(GM[y][x] == PM[0][0]){
                    boolean is_same = true;
                    for(int iy = 0; iy < P_y; iy++){
                        if(is_same == false) break;
                        for(int ix = 0; ix < P_x; ix++){
                            if(GM[y + iy][x + ix] != PM[iy][ix]){
                                is_same = false;
                                break;
                            }
                        }
                    }
                    if(is_same) return "YES";
                }
            }
        }
        return "NO";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] RC = scanner.nextLine().split(" ");

            int R = Integer.parseInt(RC[0]);

            int C = Integer.parseInt(RC[1]);

            String[] G = new String[R];

            for (int i = 0; i < R; i++) {
                String GItem = scanner.nextLine();
                G[i] = GItem;
            }

            String[] rc = scanner.nextLine().split(" ");

            int r = Integer.parseInt(rc[0]);

            int c = Integer.parseInt(rc[1]);

            String[] P = new String[r];

            for (int i = 0; i < r; i++) {
                String PItem = scanner.nextLine();
                P[i] = PItem;
            }

            String result = gridSearch(G, P);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}