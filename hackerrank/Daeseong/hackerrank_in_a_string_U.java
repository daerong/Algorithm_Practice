//Solution
//- hackerrank 문자열을 LCS 처럼 구해낸다.
//- LCS 값이 hackerrank와 같은 경우 YES를 반대의 경우 NO를 출력.
//- 1. while 루프(hakerrank에 대한 index, s 문자열에 대한 index)를 돌며 다음을 수행한다.
//- 1.1. 각 인덱스 위치의 문자를 비교한다.
//- 1.1.1. 같은 경우, 각 인덱스를 1 증가시킨다.
//- 1.1.2. 다른 경우, s의 인덱스만 1 증가시킨다.
//- 1.2. 각 index의 범위가 문자열을 벗어났는 지 확인하고 벗어났다면 반복문을 종료한다.
//- 2. hackerrank에 대한 index가 문자열의 길이와 같다면 YES를 출력하고 아니며 NO를 출력한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the hackerrankInString function below.
    static String hackerrankInString(String s) {
        String str = "hackerrank";
        int str_max = str.length();
        int str_index = 0;
        int tar_max = s.length();
        int tar_index = 0;

        while(str_index != str_max && tar_max != tar_index){
            if(str.charAt(str_index) == s.charAt(tar_index)){
                str_index++;
            }
            tar_index++;
        }

        if(str_index == str_max) return "YES";
        else return "NO";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            String result = hackerrankInString(s);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
