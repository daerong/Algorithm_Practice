//Solution
//- 최소 차이값을 가지는 숫자들을 오름차순으로 정렬하여 리턴하는 문제
//- Priority Queue에 UDS 클래스로 정렬하여 풀이.
//- 1. 주어진 arr를 sort().
//- 2. Priority Queue에 {diff, index}를 담는다. (diff 내림차순, index 오름차순)
//- 3. 첫원소를 기준으로 같은 diff에 해당하는 모든 UDS에 대해 다음을 실행한다.
//- 3.1. arr[index], arr[index + 1]을 결과에 추가한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the closestNumbers function below.
    static int[] closestNumbers(int[] arr) {
        Arrays.sort(arr);
        PriorityQueue<UDS> pq = new PriorityQueue<>();
        for(int i = 0; i < arr.length - 1; i++){
            pq.offer(new UDS(arr[i + 1] - arr[i], i));
        }

        ArrayList<Integer> answer = new ArrayList<>();
        int last_diff = Integer.MAX_VALUE;
        while(!pq.isEmpty()){
            UDS temp = pq.poll();
            if(last_diff < temp.diff) break;
            last_diff = temp.diff;
            answer.add(arr[temp.index]);
            answer.add(arr[temp.index + 1]);
        }

        int[] ans = new int[answer.size()];
        for(int i = 0; i < answer.size(); i++) ans[i] = answer.get(i);
        return ans;
    }

    private static class UDS implements Comparable<UDS>{
        int diff;
        int index;

        public UDS(int diff, int index) {
            this.diff = diff;
            this.index = index;
        }

        @Override
        public int compareTo(UDS o) {
            if (this.diff == o.diff) return this.index - o.index;
            return this.diff - o.diff;
        }
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

        int[] result = closestNumbers(arr);

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