//Solution
//- 문자열의 앞부터 뒤까지 진행하며 다음을 실행한다.
//- 1. 문자열의 맨 앞 두글자의 ASCII 값의 차이를 구한다.
//- 2. 문자열의 맨 뒤 두글자의 ASCII 값의 차이를 구한다.
//- 3. 두 차이를 비교하여 다르면 "Not Funny"를 리턴.
//- 4. 모든 글자에 대해 차이가 일정하면 "Funny"를 리턴.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the funnyString function below.
    static String funnyString(String s) {
        int last_locate = s.length() - 1;
        for(int i = 1; i < s.length(); i++){
            int front = s.charAt(i) - s.charAt(i - 1);
            if(front < 0) front *= -1;
            int back = s.charAt(last_locate - i + 1) - s.charAt(last_locate - i);
            if(back < 0) back *= -1;

            System.out.println("i = " + i + ", " + front + ", " + back);

            if(front != back) return "Not Funny";
        }

        return "Funny";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            String result = funnyString(s);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}