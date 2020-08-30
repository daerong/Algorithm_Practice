//Solution
//- 앞과 뒤를 선택할 수 있지만 동일한 말로 순차적으로 한 방향만 더하는 방식을 사용하며 된다.
//- 홀수의 갯수가 홀수개면 No를 출력하면 된다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the fairRations function below.
    static int fairRations(int[] B) {
        int answer = 0;
        for(int i = 1; i < B.length; i++){
            if(B[i - 1] % 2 == 0) continue;
            answer += 2;
            B[i] += 1;
        }
        if(B[B.length - 1] % 2 == 1) return -1;
        else return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] B = new int[N];

        String[] BItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < N; i++) {
            int BItem = Integer.parseInt(BItems[i]);
            B[i] = BItem;
        }

        int result = fairRations(B);

        if(result == -1) bufferedWriter.write("NO");
        else bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
