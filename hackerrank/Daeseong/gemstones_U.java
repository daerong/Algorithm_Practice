Solution
- 주어진 문자열에서 중복된 알파벳의 수를 출력하는 문제
- 1. 문자열의 갯수만큼 알파벳 체크할 배열을 만든다.
- 2. 알파벳을 체크한다.
- 3. 모두 있는 알파벳의 수 출력
- 쉬프트 연산을 사용하면 더 적은 복잡도로 문제해결이 가능하다.

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

        boolean[][] check = new boolean[arr.length][26];

        for(int i = 0; i < arr.length; i++){
            Arrays.fill(check[i], false);
            for(int j = 0; j < arr[i].length(); j++){
                int temp = arr[i].charAt(j) - 'a';
                System.out.println(temp);
                check[i][temp] = true;
            }
        }

        for(int k = 0; k < 26; k++){
            boolean all_true = true;
            for(int i = 0; i < arr.length; i++){
                if(!check[i][k]) {
                    all_true = false;
                    break;
                }
            }
            if(all_true) answer++;
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