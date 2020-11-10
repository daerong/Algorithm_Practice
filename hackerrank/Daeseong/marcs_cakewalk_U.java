//Solution
//- pow(2, n) * arr[n]의 최소값을 구하는 문제.
//- 1. 주어진 calorie[] 배열을 sort
//- 2. temp = pow(2, calorie.length)를 저장.
//- 3. calorie[]를 순회하며 다음을 실행한다.
//- 3.1. answer에 calorie[i]와 temp를 곱한 값을 더한다.
//- 3.2. temp를 2로 나눈다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the marcsCakewalk function below.
    static long marcsCakewalk(int[] calorie) {
        long answer = 0;
        Arrays.sort(calorie);
        long temp = (long) Math.pow(2, calorie.length - 1);
        for(int i = 0; i < calorie.length; i++){
            answer += temp * calorie[i];
            temp /= 2;
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] calorie = new int[n];

        String[] calorieItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int calorieItem = Integer.parseInt(calorieItems[i]);
            calorie[i] = calorieItem;
        }

        long result = marcsCakewalk(calorie);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}