//Solution
//- index 0과 비교하여 작은 그룹, 같은 그룹, 큰 그룹으로 나눈다.
//- 최종적으로 {작은 그룹} + {같은 그룹} + {큰 그룹} 순서로 출력한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the quickSort function below.
    static int[] quickSort(int[] arr) {
        Queue<Integer> left = new LinkedList<>();
        Queue<Integer> same = new LinkedList<>();
        Queue<Integer> right = new LinkedList<>();
        int target = arr[0];
        for(int i = 0; i < arr.length; i++){
            if(target > arr[i]) left.offer(arr[i]);
            else if(target < arr[i]) right.offer(arr[i]);
            else same.offer(arr[i]);
        }
        int index = 0;
        while(!left.isEmpty()) arr[index++] = left.poll();
        while(!same.isEmpty()) arr[index++] = same.poll();
        while(!right.isEmpty()) arr[index++] = right.poll();

        return arr;
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

        int[] result = quickSort(arr);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}