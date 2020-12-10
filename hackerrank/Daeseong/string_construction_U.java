//Solution
//- 문자에 쓰인 알파벳의 종류를 구하는 문제
//- 처음 문제해석을 잘못함. (번역기를 믿지 말자)
//- 1. 알파벳을 s에서 p로 옮기면 1을 증가시키고
//- 2. p를 다시 p에 이어 붙이면 점수를 증가시킬 필요가 없는 줄 알았음.
//- 풀이랄 건 없지만 한 번 적어본다.
//- 1. chk[26] 배열을 false로 초기화
//- 2. s의 각 문자에 해당하는 chk[]비트를 true로 변경.
//- 3. chk[] 배열의 true 갯수를 리턴.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the stringConstruction function below.
    static int stringConstruction(String s) {
        int answer = 0;
        boolean[] chk = new boolean[26];
        Arrays.fill(chk, false);
        for(int i = 0; i < s.length(); i++){
            chk[s.charAt(i) - 'a'] = true;
        }
        for(int i = 0; i < 26; i++) if(chk[i]) answer += 1;

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = stringConstruction(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
