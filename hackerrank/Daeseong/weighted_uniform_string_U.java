//Solution
//- 주어진 방식대로 unordered map을 만들고 queries에 해당하는 원소가 있는 지 없는 지 판단하는 문제
//- 1. s 문자열의 각 위치에 대해 다음을 수행한다.
//- 1.1. 알파벳에 해당하는 index(a = 1, b = 2 ... z = 26)를 구한다.
//- 1.2. 현재 위치를 기준으로 앞쪽에 연속되는 문자의 갯수(length)를 구한다.
//- 1.3. index * length를 unordered map에 추가한다.
//- 2. queries의 각 원소에 대해 다음을 수행한다.
//- 2.1. unordered map에 있으면 string 배열에 Yes를 추가한다.
//- 2.2. unordered map에 없으면 string 배열에 No를 추가한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the weightedUniformStrings function below.
    static String[] weightedUniformStrings(String s, int[] queries) {
        String[] answer = new String[queries.length];

        HashMap<Integer, Integer> m = new HashMap<>();

        for(int i = 0; i < s.length(); i++){
            int length = 0;
            for(int j = 0; i - j >= 0; j++){
                if(s.charAt(i) == s.charAt(i - j)) length++;
                else break;
            }

            int temp = s.charAt(i) - 'a';
            temp++;
            if(!m.containsKey(temp * length)) m.put(temp * length, 1);
        }

        for(int i = 0; i < queries.length; i++){
            if(m.containsKey(queries[i])) answer[i] = "Yes";
            else answer[i] = "No";
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        int queriesCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] queries = new int[queriesCount];

        for (int i = 0; i < queriesCount; i++) {
            int queriesItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            queries[i] = queriesItem;
        }

        String[] result = weightedUniformStrings(s, queries);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(result[i]);

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
