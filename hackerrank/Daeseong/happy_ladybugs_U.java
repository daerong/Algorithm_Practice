//Solution
//- 문제를 잘 이해하지 못해서 꽤 오래걸린 문제, 풀이과정은 다음과 같다.
//- 1. _(언더바)를 제외한 문자열을 얻는다.
//- 2. 1에서 얻은 문자열을 구성하는 각각의 알파벳의 갯수를 얻는다.
//- 3. 가능 여부를 판단한다.
//    - 3-1. 알파벳 갯수가 1개이면 NO를 출력
//    - 3-2. _(언더바)가 없으면서 연속된 알파벳이 업는 경우 NO를 출력
//    - 3-3. 그 외 YES 출력

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the happyLadybugs function below.
    static String happyLadybugs(String b) {
        String cp_b = b;
        cp_b = cp_b.replaceAll("_", "");
        char[] arr = cp_b.toCharArray();
        int[] alphabet = new int[26];
        for(int i = 0; i < arr.length; i++){
            if(arr[i] == '_') continue;
            alphabet[arr[i] - 'A'] += 1;
        }

        for(int i = 0; i < 26; i++){
            if(alphabet[i] == 1) return "NO";
        }
        if(b.length() - cp_b.length() == 0){
            for(int i = 1; i < cp_b.length() - 1; i++){
                if(arr[i - 1] != arr[i] && arr[i] != arr[i + 1]) return "NO";
            }
        }

        return "YES";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int g = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int gItr = 0; gItr < g; gItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            String b = scanner.nextLine();

            String result = happyLadybugs(b);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}