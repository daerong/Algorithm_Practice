//Solution
//- 몇몇 경우를 제외하고 기본 조합으로 나타낼 수 있다.
//- 예외 경우는 각각 문장을 조합하여 나타낸다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static String[] arr = {
            "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
            "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
            "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"
    };
    // Complete the timeInWords function below.
    static String timeInWords(int h, int m) {
        String answer = "";
        switch (m){
            case 0:
                answer = arr[h] + " o' clock";
                break;
            case 1:
                answer = "one minute past " + arr[h];
                break;
            case 15:
                answer = "quarter past " + arr[h];
                break;
            case 30:
                answer = "half past " + arr[h];
                break;
            case 45:
                answer = "quarter to " + arr[h + 1];
                break;
            default:
                if(m > 30){
                    answer = arr[60 - m] + " minutes to " + arr[h + 1];
                }else{
                    answer = arr[m] + " minutes past " + arr[h];
                }
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int h = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String result = timeInWords(h, m);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
