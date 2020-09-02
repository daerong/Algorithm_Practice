//Solution
//- 문제에서 요구하는 풀이보다 a와 b의 조합수로 문제를 풀었다.
//- n이 주어질 때 a와 b의 조합의 수는 n개로 정해진다.
//- a가 i개, b가 j개일 때 값은 a * i + b * j이며 이는 (i, j)로 표현할 수 있다.
//- 따라서 n이 주어졌을 때의 조합은 (0, n - 1), (1, n - 2), ... (n - 1, 0)이다.
//- 하지만 주의해야 할 점이 있다.
//- 1. a, b의 크기 상하관계가 없으며,
//- 2. 값의 중복이 일어날 수 있다는 것이다.
//- 풀이를 순서대로 나열하면 다음과 같다.
//- 1. (i, j)의 결과를 int 배열에 넣는다.
//- 2. 배열을 정렬한다.
//- 3. 중복을 제거한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the stones function below.
    static int[] stones(int n, int a, int b) {
        int[] result = new int[n];
        for(int i = 0; i < n; i++){
            result[i] = b * i + a * (n - i - 1);
        }

        Arrays.sort(result);
        int same = 0;
        for(int i = 1; i < n; i++){
            if(result[i - 1] == result[i]) {
                same++;
                result[i - 1] = 0;
            }
        }

        int[] answer = new int[n - same];
        int index = 0;
        for(int i = 0; i < n; i++){
            if(result[i] == 0) continue;
            answer[index] = result[i];
            index++;
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int T = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int TItr = 0; TItr < T; TItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int a = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int b = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] result = stones(n, a, b);

            for (int i = 0; i < result.length; i++) {
                bufferedWriter.write(String.valueOf(result[i]));

                if (i != result.length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
