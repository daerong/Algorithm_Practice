//Solution
//- 페이지와 섹션넘버가 일치하는 경우의 수를 구하는 문제
//- 풀이는 페이지와 섹션넘버를 증가시키며 비고했지만 다음을 통해 시간을 단축할 수 있다.
//- 1. 섹션넘버가 페이지보다 작은 경우 섹션넘버만 증가시킨다.
//- 2. 페이지넘버가 섹션넘버보다 큰 경우 반복문을 종료한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the workbook function below.
    static int workbook(int n, int k, int[] arr) {
        int answer = 0;

        int p_id = 1;
        for(int i = 0; i < n; i++){
            int p = 1;
            while(p <= arr[i]){
                if(p_id == p) answer++;
                if(p % k == 0) p_id++;
                p++;
            }

            if(arr[i] % k != 0) p_id++;
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int result = workbook(n, k, arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
