//Solution
//- index 1번째 원소부터 n - 1번째까지 다음을 실행한다.
//- 앞원소를 비교해가며 작으면 자리를 바꾼다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the insertionSort2 function below.
    static void insertionSort2(int n, int[] arr) {
        for(int i = 1; i < n; i++){
            if(arr[0] > arr[i]){
                int temp = arr[i];
                for(int j = i; j > 0; j--) arr[j] = arr[j - 1];
                arr[0] = temp;
            }else{
                int target;
                for(target = i - 1; target >= 0; target--){
                    if(arr[target] < arr[i]) break;
                }
                target++;

                int temp = arr[i];
                for(int j = i; j > target; j--) arr[j] = arr[j - 1];
                arr[target] = temp;
            }

            for(int k = 0; k < n - 1; k++) System.out.print(arr[k] + " ");
            System.out.println(arr[n - 1]);
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        insertionSort2(n, arr);

        scanner.close();
    }
}
