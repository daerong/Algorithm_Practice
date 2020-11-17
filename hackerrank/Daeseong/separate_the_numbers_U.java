//Solution
//- 주어진 문자열이 순차적으로 증가하는 숫자로 되어있는 지 확인하는 문제
//- 다음에 유의하자.
//- 1. 문자열이 "01"과 같은 경우 앞자리 '0' 때문에 성립 X
//- 풀이는 다음과 같다.
//- 1. 맨 앞이 0인 경우 "NO"
//- 2. 초기 길이 length에 대해 1부터 N/2까지 다음을 반복한다.
//- 2.1. StringBuilder의 길이가 s의 길이와 같거나 클때까지 다음을 반복한다.
//- 2.1.1. 숫자를 문자열로 치환하여 StringBuilder에 더한다.
//- 2.1.2. 해당 숫자를 1 증가시킨다.
//- 2.2. 만들어진 StringBuilder와 s를 비교하여 같으면 "YES" + 처음 숫자를 출력.
//- 3. 조건을 만족시키는 L이 없는 경우 "NO"

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the separateNumbers function below.
    static void separateNumbers(String s) {
        if (s.charAt(0) == '0') {
            System.out.println("NO");
            return;
        }

        for (int length = 1; length * 2 <= s.length(); length++) {
            long firstNumber = Long.parseLong(s.substring(0, length));

            StringBuilder sequence = new StringBuilder();
            long number = firstNumber;
            while (sequence.length() < s.length()) {
                sequence.append(number);
                number++;
            }
            if (sequence.toString().equals(s)) {
                System.out.println("YES " + firstNumber);
                return;
            }
        }

        System.out.println("NO");
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            separateNumbers(s);
        }

        scanner.close();
    }
}
