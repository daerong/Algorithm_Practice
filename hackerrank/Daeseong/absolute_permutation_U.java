Solution
- k만큼의 차이를 가지고 있는 새로운 배열을 찾는 문제
- 1. k = 0인 경우 그대로 출력하면 된다.
- 2. n % (2 * k) == 0을 성립하면 숫자의 교환을 통해 새로운 배열을 만들 수 있다.
- 2-1. 처음 k번은 k를 더하고
- 2-2. 다음 k번은 k를 뺀다.
- 2-3. 2-1~2-2를 반복하여 결과배열을 구성한다.
- 3. 1, 2에 해당하지 않는 경우 -1을 리턴.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the absolutePermutation function below.
    static int[] absolutePermutation(int n, int k) {
        int[] failed = {-1};
        int[] result = new int[n];
        if(k == 0){
            for(int i = 1; i <= n; i++){
                result[i - 1] = i;
            }

            return result;
        }
        else if(n % (2 * k) == 0){
            int addFactor = 0;
            for(int i = 0; i < n; i++){
                if(i % k == 0) addFactor++;
                if(addFactor % 2 == 0) result[i] = i + 1 - k;
                else result[i] = i + 1 + k;
            }

            return result;
        }
        else return failed;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] nk = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nk[0]);

            int k = Integer.parseInt(nk[1]);

            int[] result = absolutePermutation(n, k);

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