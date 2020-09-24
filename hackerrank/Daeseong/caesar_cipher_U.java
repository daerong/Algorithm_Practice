//Solution
//- 소, 대문자와 그 외에 처리를 나누면 된다.
//- k의 범위가 100이하의 양수이므로 26을 나눈 나머지를 취해 더한다.
//- 더한수가 'Z', 'Z'를 초과한경우 26을 더해 범위를 맞춘다.
//- Char array를 사용하되 마지막에 String.valueof()를 사용해 리턴한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the caesarCipher function below.
    static String caesarCipher(String s, int k) {
        char[] arr = s.toCharArray();
        k %= 26;
        System.out.println(k);
        for(int i = 0; i < arr.length; i++){
            if(arr[i] >= 'A' && arr[i] <= 'Z'){
                if(arr[i] + k > 'Z') arr[i] = (char) (arr[i] + k - 26);
                else arr[i] = (char) (arr[i] + k);
            }else if(arr[i] >= 'a' && arr[i] <= 'z'){
                if(arr[i] + k > 'z') arr[i] = (char) (arr[i] + k - 26);
                else arr[i] = (char) (arr[i] + k);
            }
        }

        return String.valueOf(arr);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String s = scanner.nextLine();

        int k = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String result = caesarCipher(s, k);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}