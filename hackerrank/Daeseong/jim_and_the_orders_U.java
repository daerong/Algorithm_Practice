//Solution
//- 일찍 도착한 순서대로 index를 리턴.
//- 1. Priority Queue에 time과 index를 저장 (time의 오름차순)
//- 2. 순서대로 answer[] 배열에 저장

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the jimOrders function below.
    static int[] jimOrders(int[][] orders) {
        int[] answer = new int[orders.length];
        PriorityQueue<UDS> pq = new PriorityQueue<UDS>();
        for(int i = 0; i < orders.length; i++){
            pq.offer(new UDS(orders[i][0] + orders[i][1], i + 1));
        }

        for(int i = 0; i < orders.length; i++){
            answer[i] = pq.poll().index;
        }
        return answer;
    }

    private static class UDS implements Comparable<UDS>{
        int time;
        int index;

        public UDS(int time, int index) {
            this.time = time;
            this.index = index;
        }

        @Override
        public int compareTo(UDS o) {
            if(this.time == o.time) return this.index - o.index;
            return this.time - o.time;
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[][] orders = new int[n][2];

        for (int i = 0; i < n; i++) {
            String[] ordersRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int ordersItem = Integer.parseInt(ordersRowItems[j]);
                orders[i][j] = ordersItem;
            }
        }

        int[] result = jimOrders(orders);

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