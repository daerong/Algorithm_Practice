//Solution
//- 공백으로 인해 출력이 매끄럽지 않다. 출력에 주의

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the insertionSort1 function below.
    static void insertionSort1(int n, int[] arr) {
        boolean bool = true;
        while(bool) {
            bool = false;
            int index = 0;
            int target = 0;
            for (int i = 1; i < arr.length; i++) {
                if (arr[i - 1] > arr[i]) {
                    bool = true;
                    index = i;
                    target = arr[i];
                    break;
                }
            }

            if(!bool) break;

            while (index >= 0) {
                if (index == 0) arr[0] = target;
                else {
                    if(arr[index - 1] < target){
                        arr[index] = target;

                        String str = "" + arr[0];
                        for (int j = 1; j < arr.length; j++) {
                            str += " " + arr[j];
                        }
                        System.out.println(str);

                        break;
                    }
                    arr[index] = arr[index - 1];
                }

                String str = "" + arr[0];
                for (int j = 1; j < arr.length; j++) {
                    str += " " + arr[j];
                }
                System.out.println(str);

                index--;
            }
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

        insertionSort1(n, arr);

        scanner.close();
    }
}