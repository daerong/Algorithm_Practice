//Solution
//- 아래의 실수로 인해 생각보다 많은 시간을 소요했다.
//- 1. 문제에서 주어진 floor(sqrt) <= r <= c <= ceilling(sqrt)를 잘못 이해하고 floor(sqrt)와 ceil(sqrt)를 바로사용.
//- 2. Matrix의 r, c를 swap하는 과정에서 기존 String에 접근하는 방식이 잘못됨.
//- 3. String에 char 배열을 바로 더하는 과정에서 오류가 발생.
//- 다음과 같이 수행하여 결과를 얻을 수 있었다.
//- 1. 길이의 제곱근을 구한 뒤 배열 크기를 구한다.
//- 1-1. sqrt를 사용해 제곱근을 구함.
//- 1-2. floor, ceil을 사용해 올림, 내림을 구함.
//- 1-3. floor * ceil의 크기가 주어진 문자의 길이보다 작은 경우 ceil, ceil 사용.
//- 2. 배열에 주어진 문자열을 순차적으로 집어넣는다. c * rL + r(rL은 row의 길이)
//- 3. 배열의 문자를 문자열에 차례대로 더한다.
//- 3-1. 각 행의 마지막 원소가 공백문자인 경우 그 전까지만 사용한다.
//- 3-2. String.valueOf(arr[i])를 사용해 문자열을 더한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the encryption function below.
    static String encryption(String s) {
        int sL = s.length();
        double L = Math.sqrt(sL);
        int dL = (int) Math.floor(L);
        int uL = (int) Math.ceil(L);
        int nr = uL;
        int nc = dL;
        if(nr * nc < sL) nc = uL;

        System.out.println(nr + " " + nc);

        char[][] arr = new char[nr][nc];
        for(int r = 0; r < nr; r++){
            for(int c = 0; c < nc; c++){
                if(c * nr + r >= sL) arr[r][c] = ' ';
                else arr[r][c] = s.charAt(c * nr + r);
            }
        }

        String answer = "";
        for(int i = 0; i < nr; i++){
            if(arr[i][nc - 1] == ' ') answer += String.valueOf(arr[i]);
            else answer += String.valueOf(arr[i]) + " ";
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = encryption(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}