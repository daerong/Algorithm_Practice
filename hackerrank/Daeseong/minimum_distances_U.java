//Solution
//- 같은 숫자 간의 거리 중 최소값을 출력하는 문제
//- Hashmap을 사용해 각각을 입력하고 기존 값이 있을 시 최소값을 업데이트한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumDistances function below.
    static int minimumDistances(int[] a) {
        int answer = 1000;
        HashMap<Integer, Integer> m = new HashMap<>();
        int len = a.length;
        for(int i = 0; i < len; i++){
            if(!m.containsKey(a[i])) m.put(a[i], i);
            else{
                int start = m.get(a[i]);
                answer = Math.min(answer, i - start);
            }
        }
        if(answer == 1000) return -1;
        else return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] a = new int[n];

        String[] aItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int aItem = Integer.parseInt(aItems[i]);
            a[i] = aItem;
        }

        int result = minimumDistances(a);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}