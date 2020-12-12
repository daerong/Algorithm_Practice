//Solution
//- 문자를 주어진 조건으로 쪼개 그 문자로 만들 수 있는 Substring의 조합을 구하는 문제.
//= 풀이는 다음과 같다.
//- 1. queries의 조건대로 문자열을 쪼갠다.
//- 1.1. queries[n][0]은 시작위치, queries[n][1]은 끝 위치이다.
//- 1.2. substring(시작위치, 끝위치 + 1)이므로 해당 함수를 이용한다.
//- 2. 1.에서 구한 문자열의 가능한 조합의 수를 구한다.
//- 2.1. 문자를 다음의 조건으로 자른다.
//- 2.1.1. 0 ~ n-1 까지 i를 증가시킨다.
//- 2.1.2. 1부터 len을 증가시킨다.
//- 2.1.3. i + len이 n보다 작거나 같을 때까지 다음을 수행한다.
//- 2.1.3.1. substring(i, i + len)을 구한다.
//- 2.1.3.2. 2.1.3.1.에서 구한 substring이 HashMap에 있는 지 확인한다.
//- 2.1.3.3. 없을 경우, HashMap에 추가한다.
//- 3. 최종적으로 HashMap에 저장된 원소의 갯수를 결과 배열에 추가한다.
//- 4. 결과 배열을 리턴한다.

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    static int[] countSubstrings(String s, int[][] queries) {
        int[] answer = new int[queries.length];
        for(int i = 0; i < queries.length; i++){
            String str = s.substring(queries[i][0], queries[i][1] + 1);
            HashMap<String, Boolean> m = new HashMap<>();
            for(int j = 0; j < str.length(); j++){
                for(int len = 1; j + len <= str.length(); len++){
                    if(!m.containsKey(str.substring(j, j + len))){
                        m.put(str.substring(j, j + len), true);
                    }
                }
            }

            answer[i] = m.size();
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nq = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nq[0].trim());

        int q = Integer.parseInt(nq[1].trim());

        String s = scanner.nextLine();

        int[][] queries = new int[q][2];

        for (int queriesRowItr = 0; queriesRowItr < q; queriesRowItr++) {
            String[] queriesRowItems = scanner.nextLine().split(" ");

            for (int queriesColumnItr = 0; queriesColumnItr < 2; queriesColumnItr++) {
                int queriesItem = Integer.parseInt(queriesRowItems[queriesColumnItr].trim());
                queries[queriesRowItr][queriesColumnItr] = queriesItem;
            }
        }

        int[] result = countSubstrings(s, queries);

        for (int resultItr = 0; resultItr < result.length; resultItr++) {
            bufferedWriter.write(String.valueOf(result[resultItr]));

            if (resultItr != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
