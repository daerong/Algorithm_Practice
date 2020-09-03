//Solution
//- 배열 공간의 크기가 3을 시작으로 2배씩 증가한다.
//- 각각의 번호는 누적되나, value는 배열의 크기를 시작으로 1까지 줄어든다.
//- 누적을 무시하고 배열의 공간크기로 번호를 구하는 수식은 (배열의 크기 - 위치 + 1)이다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the strangeCounter function below.
    static long strangeCounter(long t) {
        long value = t;
        long temp = 3;
        while(value > temp){
            value -= temp;
            temp *= 2;
        }

        return temp - value + 1;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        long t = scanner.nextLong();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long result = strangeCounter(t);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}