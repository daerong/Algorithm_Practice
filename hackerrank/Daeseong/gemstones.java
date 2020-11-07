//Solution
//- 복수 문자열에 공통적으로 들어있는 문자의 수를 구하는 문제
//- 1. 각 문자열의 인덱스를 설정한다 (a = 0, z = 25)
//- 2. 각 문자열에 대해 다음을 수행한다.
//- 2.1. 각 문자에 대해 다음을 수행한다.
//- 2.1.1. 방문체크(각 문자열에 대해 중복되는 문자를 찾는 과정)
//- 2.1.1.1. 기 방문 시, 다음 반복을 수행.
//- 2.1.1.2. 미 방문 시, 방문체크와 해당하는 알파벳에 대한 cnt[인덱스] 값을 1 증가시킨다.
//- 3. cnt[]에 대해 문자열의 갯수 N과 같은 값의 갯수를 찾는다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the gemstones function below.
    static int gemstones(String[] arr) {
        int answer = 0;
        int N = arr.length;
        HashMap<Character, Integer> m = new HashMap<>();
        for(int m_index = 0; m_index < 26; m_index++) m.put((char) ('a' + m_index), m_index);
        boolean[] visited = new boolean[26];
        int[] cnt = new int[26];
        Arrays.fill(cnt, 0);
        for(int i = 0; i < N; i++){
            Arrays.fill(visited, false);
            for(int j = 0; j < arr[i].length(); j++){
                if(visited[m.get(arr[i].charAt(j))]) continue;
                visited[m.get(arr[i].charAt(j))] = true;
                cnt[m.get(arr[i].charAt(j))] += 1;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == N) {
                answer++;
            }
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String[] arr = new String[n];

        for (int i = 0; i < n; i++) {
            String arrItem = scanner.nextLine();
            arr[i] = arrItem;
        }

        int result = gemstones(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
