//Solution
//- 문자열에서 "010"의 갯수를 찾는 문제
//- 중복된 "010"은 없다.
//- 1. 1을 찾아서 양옆에 0을 찾는다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the beautifulBinaryString function below.
    static int beautifulBinaryString(String b) {
        int answer = 0;
        for(int i = 1; i < b.length() - 1; i++){
            if(b.charAt(i) == '1'){
                if(b.charAt(i - 1) == '0' && b.charAt(i + 1) == '0') {
                    answer++;
                    i += 2;
                }
            }
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String b = scanner.nextLine();

        int result = beautifulBinaryString(b);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}