//Solution
//- SOS를 반복하는 반복 문자열과 비교하여 다른 갯수를 찾아내는 문제
//- 1. 3으로 나눈 나머지에 따라 다음을 실행한다.
//- 1.1. 나머지가 홀수인 경우, S와 다른 지 확인한다.
//- 1.2. 나머지가 짝수인 경우, O와 다른 지 확인한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the marsExploration function below.
    static int marsExploration(String s) {
        int answer = 0;
        for(int i = 0; i < s.length(); i++){
            switch(i % 3){
                case 0:
                case 2:
                    if(s.charAt(i) != 'S') answer++;
                    break;
                case 1:
                    if(s.charAt(i) != 'O') answer++;
                    break;
            }
        }

        return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        int result = marsExploration(s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
