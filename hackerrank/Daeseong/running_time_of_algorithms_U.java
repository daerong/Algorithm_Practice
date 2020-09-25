//Solution
//- 총 교환한 수를 구한다.
//- 1. 0번 원소를 선택한다.
//- 2. 앞의 원소와 비교한다.(없으면 무시)
//- 2-1. 앞의 원소가 더 클 경우, 위치를 바꾸어 2번으로 돌아간다.
//- 2-2. 앞의 원소가 작거나 같을 경우 1번으로 돌아가 다음 원소를 선택한다.
//- 3. 모든 원소에 대해 수행했을 때, 2-1번의 수행횟수를 리턴한다.


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the runningTime function below.
    static int runningTime(int[] arr) {
        int answer = 0;
        for(int i = 1; i < arr.length; i++){
            for(int j = i - 1; j >= 0; j--){
                if(arr[j] > arr[j + 1]){
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    answer++;
                }else break;
            }
        }

        return answer;
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

        int result = runningTime(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}