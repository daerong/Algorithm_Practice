//Solution
//- If you use substring, can split numbers.
//- 두 수를 나눌 때, 홀수이면 뒤에 숫자가 한자리가 많다.
//- string 형태로 변환하여 나누는 것이 직관적이여서 그렇게 사용했다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the kaprekarNumbers function below.
    static void kaprekarNumbers(int p, int q) {
        String answer = "";

        for(int i = p; i <= q; i++){
            long temp = (long)i * i;
            String str = "" + temp;
            int len = str.length();
            if(len == 1){
                if (i == temp) {
                    answer += i + " ";
                }
            }else {
                int back = (len + 1) / 2;
                int front = len - back;
                String front_sub = str.substring(0, front);
                String back_sub = str.substring(front, len);
                front = Integer.parseInt(front_sub);
                back = Integer.parseInt(back_sub);

                int result = front + back;

                if (i == result) {
                    answer += i + " ";
                }
            }
        }

        if(answer == "") System.out.println("INVALID RANGE");
        else System.out.println(answer);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int p = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        kaprekarNumbers(p, q);

        scanner.close();
    }
}