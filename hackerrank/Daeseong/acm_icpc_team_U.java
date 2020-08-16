/*
Solution
- 이중 for문을 사용하여 비교했다.
- 최대 팀구성이 필요하므로 비교 도중에 최대가 아닌 경우 중단하도록 설정하였다.
- 둘다 0인 경우는 팀 인원이 1줄어드므로 둘 다 0인 경우를 제외하며 비교한다.
 */

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the acmTeam function below.
    static int[] acmTeam(String[] topic) {
        int diffMin = 999;
        int sameCnt = 0;
        int n = topic.length;
        int m = topic[0].length();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int diffCnt = 0;
                for(int index = 0; index < m; index++){
                    if(topic[i].charAt(index) == '0' && topic[j].charAt(index) == '0') diffCnt++;
                    if(diffMin < diffCnt) break;
                }
                if(diffCnt == diffMin) sameCnt++;
                else if(diffMin > diffCnt) {
                    diffMin = diffCnt;
                    sameCnt = 1;
                }
            }
        }

        int[] result = {m - diffMin, sameCnt};
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        String[] topic = new String[n];

        for (int i = 0; i < n; i++) {
            String topicItem = scanner.nextLine();
            topic[i] = topicItem;
        }

        int[] result = acmTeam(topic);

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
