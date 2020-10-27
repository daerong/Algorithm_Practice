//Solution
//- 문자 좌우대칭 확인하는 문제
//- 1. 중간을 기준으로 나눈다.
//- 1.1. 짝수의 경우 좌우 대칭으로 나뉨
//- 1.2. 홀수의 경우 중간제외 대칭으로 나뉨
//- 2. 다르면 그 차이값을 answer에 더함

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the theLoveLetterMystery function below.
    static int theLoveLetterMystery(String s) {
        int answer = 0;
        if(s.length() % 2 == 1){
            int mid = s.length() / 2;
            for(int i = 1; i <= mid; i++){
                if(s.charAt(mid - i) != s.charAt(mid + i)){
                    answer += Math.abs(s.charAt(mid - i) - s.charAt(mid + i));
                }
            }
        }else{
            int right = s.length() / 2;
            int left = right - 1;
            for(int i = 0; left - i >= 0; i++){
                if(s.charAt(left - i) != s.charAt(right + i)){
                    answer += Math.abs(s.charAt(left - i) - s.charAt(right + i));
                }
            }
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = theLoveLetterMystery(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}