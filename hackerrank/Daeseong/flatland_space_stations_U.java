//Solution
//- 우주정거장과 거리의 최대값을 구하는 문제
//- 다음에 유의하면 어려움 없이 해결가능하다.
//- 1. c는 정렬되어 있지 않다.
//- 2. 0과 n-1번째 도시와의 거리는 2로 나눌 필요가 없다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the flatlandSpaceStations function below.
    static int flatlandSpaceStations(int n, int[] c) {
        int m = c.length;
        if(n == m) return 0;
        Arrays.sort(c);

        int result = Math.max(c[0], n - 1 - c[m - 1]);
        for(int i = 1; i < c.length; i++){
            result = Math.max(result, (c[i] - c[i - 1]) / 2);
        }

        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        int[] c = new int[m];

        String[] cItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            int cItem = Integer.parseInt(cItems[i]);
            c[i] = cItem;
        }

        int result = flatlandSpaceStations(n, c);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
