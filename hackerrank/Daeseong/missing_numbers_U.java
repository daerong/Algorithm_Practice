//Solution
//- 두 배열을 비교하여 없는 숫자를 찾아 오름차순으로 정렬하는 문제.
//- 중복이 불가한 지 몰라서 헤맸던 문제. 내 Hackos... ㅠㅠ
//- 1. HashMap에 index를 기록 (index는 0~)
//- 2. cnt[index]에 숫자를 계수.
//- 3. arr[] 배열에 있으면 하나씩 뺌.
//- 4. cnt[index]를 돌며 남은 숫자를 하나씩 추가한다.
//- 5. 오름차순으로 정렬.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the missingNumbers function below.
    static int[] missingNumbers(int[] arr, int[] brr) {
        int[] cnt = new int[arr.length];
        Arrays.fill(cnt, 0);
        HashMap<Integer, Integer> m = new HashMap<>();
        int m_index = 0;

        for(int i = 0; i < brr.length; i++){
            if(!m.containsKey(brr[i])){
                m.put(brr[i], m_index++);
            }

            cnt[m.get(brr[i])] += 1;
        }

        for(int i = 0; i < arr.length; i++){
            cnt[m.get(arr[i])] -= 1;
        }

        LinkedList<Integer> list = new LinkedList<>();
        for(int i = 0; i < brr.length; i++){
            if(cnt[m.get(brr[i])] > 0){
                list.add(brr[i]);
                cnt[m.get(brr[i])] = 0;
            }
        }

        int[] answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            answer[i] = list.get(i);
        }

        Arrays.sort(answer);
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

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] brr = new int[m];

        String[] brrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            int brrItem = Integer.parseInt(brrItems[i]);
            brr[i] = brrItem;
        }

        int[] result = missingNumbers(arr, brr);

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