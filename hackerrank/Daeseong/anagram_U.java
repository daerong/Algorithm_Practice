//Solution
//- Anagram이란 문자를 같은 크기로 분할 했을 때, 좌우가 다르면서 구성 성분이 같은 문자열이다.
//- 따라서 출력은 다음과 같다.
//- 1. 같은 크기로 나눌 수 없는 경우, return -1
//- 2. 좌우가 같은 경우, return 1
//- 3. 그 외, return 교체할 문자의 수
//- 풀이는 다음과 같다.
//- 1. 문자열의 길이가 1인 경우, -1을 리턴
//- 2. 문자열을 같은 크기로 나눈다.
//- 3. 나눠진 문자열이 같으면 1을 리턴
//- 4. 각 문자열을 이루는 알파벳의 갯수를 one_cnt[], two_cnt[]에 저장한다.
//- 5. one_cnt[], two_cnt[]의 각 성분의 차이를 저장한다.
//= 6. 5.에서 구한 차이값의 절반을 리턴

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the anagram function below.
    static int anagram(String s) {
        if(s.length() % 2 == 1) return -1;
        String one = s.substring(0, s.length() / 2);
        String two = s.substring(s.length() / 2);
        if(one.equals(two)) return 1;

        int[] one_cnt = new int[26];
        int[] two_cnt = new int[26];
        Arrays.fill(one_cnt, 0);
        Arrays.fill(two_cnt, 0);
        for(int i = 0; i < s.length() / 2; i++){
            one_cnt[one.charAt(i) - 'a'] += 1;
            two_cnt[two.charAt(i) - 'a'] += 1;
        }

        int answer = 0;
        for(int i = 0; i < 26; i++){
            answer += Math.abs(one_cnt[i] - two_cnt[i]);
        }

        return answer / 2;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = anagram(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
