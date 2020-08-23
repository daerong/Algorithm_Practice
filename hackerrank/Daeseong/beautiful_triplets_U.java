//Solution
//- d만큼 차이나는 숫자가 몇개인지 구하는 문제.
//- 우선 주어진 값을 n배열에 추가하여 갯수를 저장하고,
//- 같은 숫자가 여러개일 경우 각각 경로에 포함되므로 곱연산으로 구했다.
//- 중앙에 있는 숫자를 기준으로 양쪽을 비교한다면 n-d의 갯수 * n의 갯수 * n+d의 갯수로 구할 수 있다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the beautifulTriplets function below.
    static int beautifulTriplets(int d, int[] arr) {
        int[] m = new int[20041];
        Arrays.fill(m, 0);
        for(int i = 0; i < arr.length; i++){
            m[arr[i]] += 1;
        }

        int last = arr[arr.length - 1];
        int answer = 0;
        for(int i = 0; i <= last; i++){
            answer += m[i] * m[i + d] * m[i + 2 * d];
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int result = beautifulTriplets(d, arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
