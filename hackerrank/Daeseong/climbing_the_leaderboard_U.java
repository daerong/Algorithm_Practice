//Solution
//- Using Hashmap and Binary Search.
//- Key를 등수로 Value를 점수로 하는 HashMap을 만들어 중복을 제거하여 입력.
//- 주어진 배열이 정렬되어 있으므로 이진 탐색을 하여 결과를 구한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the climbingLeaderboard function below.
    static int[] climbingLeaderboard(int[] scores, int[] alice) {
        int N = alice.length;
        int[] answer = new int[N];
        HashMap<Integer, Integer> m = new HashMap<>();
        m.put(0, Integer.MAX_VALUE);
        int m_index = 1;
        int temp = 0;
        for(int i = 0; i < scores.length; i++){
            if(temp == scores[i]) continue;
            temp = scores[i];
            m.put(m_index, scores[i]);
            m_index++;
        }

        int index = 0;
        for(int i = 0; i < N; i++){
            int start = 1;
            int end = m_index - 1;
            int mid = 0;
            while(true){
                mid = (start + end) / 2;
                if(start > end) {
                    answer[index++] = mid + 1;
                    break;
                }
                int factor = m.get(mid);
                if(factor > alice[i]) start = mid + 1;
                else if(factor < alice[i]) end = mid - 1;
                else {
                    answer[index++] = mid;
                    break;
                }
            }
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int scoresCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] scores = new int[scoresCount];

        String[] scoresItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < scoresCount; i++) {
            int scoresItem = Integer.parseInt(scoresItems[i]);
            scores[i] = scoresItem;
        }

        int aliceCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] alice = new int[aliceCount];

        String[] aliceItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < aliceCount; i++) {
            int aliceItem = Integer.parseInt(aliceItems[i]);
            alice[i] = aliceItem;
        }

        int[] result = climbingLeaderboard(scores, alice);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}