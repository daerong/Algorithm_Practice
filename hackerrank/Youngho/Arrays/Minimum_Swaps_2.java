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
        int count = 0;
        //2중 for문을 써서 selection sort를 써도 되는데, 몇개 케이스는 타임오버가 난다.
        //조건을 더 걸 수도 없다. 그러면 sort자체가 틀렸다는거니까 새로운 규칙을 찾자.
        for(int i=0; i<len; i++){
            //Idea : 계속 첫번째인자를 바꾸다가 첫 인자가 1이면 2번째 인자를 계속 바꾼다.
            while(arr[i] != i+1){   
                int temp = arr[i];
                arr[i] = arr[arr[i]-1];
                arr[temp-1] = temp; //여기에 temp-1을 써줘야한다. 윗줄에서 arr[i] 값이 바뀌었으니까.
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
