//Solution
//- 1번 문자열에서 2번 문자열을 만들기 위해 삭제하거나 추가해야할 알파벳 갯수를 구하는 문제
//- LCS 인줄 알고 풀었으나 알파벳 갯수비교로 구할 수 있었다.
//- 1. 1번 문자열의 각 알파벳의 갯수를 구한다.
//- 2. 2번 문자열의 각 알파벳의 갯수를 구한다.
//- 3. 1.과 2.에서 구한 각 알파벳 숫자의 차이 값의 합을 구한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the makingAnagrams function below.
    static int makingAnagrams(String s1, String s2) {
        int[] alphabet = new int[26];
        Arrays.fill(alphabet, 0);

        for(int i = 0; i < s1.length(); i++) {
            alphabet[s1.charAt(i) - 'a'] += 1;
        }

        for(int j = 0; j < s2.length(); j++) {
            alphabet[s2.charAt(j) - 'a'] -= 1;
        }

        int answer = 0;
        for(int k = 0; k < 26; k++){
            answer += Math.abs(alphabet[k]);
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s1 = scanner.nextLine();

        String s2 = scanner.nextLine();

        int result = makingAnagrams(s1, s2);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}