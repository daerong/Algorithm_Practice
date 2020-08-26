//Solution
//- 초콜렛을 먹고 포장지를 m개 가져오면 1개를 더준다고 할 때 몇개를 먹을 수 있는 지 구하는 문제이다.
//- 1. n / c로 처음 구매 가능한 갯수를 구한다. cnt = n / c
//- 2. m의 배수만큼 제외한다. cnt += x * m; (x는 묶음의 갯수)
//- 3. 묶음의 갯수 만큼 초콜렛을 추가한다. cnt += x;
//- 4. 갯수가 m보다 작을 때까지 2~3을 반복한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the chocolateFeast function below.
    static int chocolateFeast(int n, int c, int m) {
        int answer = 0;
        int cnt = n / c;
        while(cnt >= m){
            int box = cnt / m;
            cnt -= box * m;
            cnt += box;
            answer += box * m;
        }

        return answer += cnt;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] ncm = scanner.nextLine().split(" ");

            int n = Integer.parseInt(ncm[0]);

            int c = Integer.parseInt(ncm[1]);

            int m = Integer.parseInt(ncm[2]);

            int result = chocolateFeast(n, c, m);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}