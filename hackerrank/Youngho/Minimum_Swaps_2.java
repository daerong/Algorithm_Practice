https://www.hackerrank.com/challenges/minimum-swaps-2/problem2314?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrayslink :
time : 10 min
비고 : 15개중 4개의 test case가 런타임 에러 발생.. Worst case가 On2보다 빨라야 함을 의미 -> 연산 필요

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumSwaps function below.
    static int minimumSwaps(int[] arr) {
        int len = arr.length;
        int min = 0;
        int count = 0;
        int index = 0;
        for(int i=0; i<len-1; i++){
            min = arr[i];
            for(int j=i+1; j<len; j++){
                if(min > arr[j]){
                    min = arr[j];
                    index = j;
                }
            }
            if(min < arr[i]){
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
                count++;
            }
        }
        return count;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int res = minimumSwaps(arr);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
