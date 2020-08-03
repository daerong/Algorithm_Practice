//link : https://www.hackerrank.com/challenges/balanced-brackets/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=stacks-queues&isFullScreen=true
//try : 1
//샘플 테스트케이스는 통과했으나 나머지 15개는 Runtime Error 발생

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static String isBalanced(String s) {
        int len = s.length();
        Stack<Character> stack = new Stack<Character>();

        for(int i=0; i<len; i++){
            if(s.charAt(i) == '{' ||
               s.charAt(i) == '(' ||
               s.charAt(i) == '['){
                   stack.push(s.charAt(i));
               }
            else{
                char temp = stack.pop();
                if(
                    (temp == '{' && s.charAt(i) != '}') ||
                    (temp == '(' && s.charAt(i) != ')') ||
                    (temp == '[' && s.charAt(i) != ']')                    
                ){
                  return "NO";  
                }
            }
        }
        return "YES";
    }


    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String s = scanner.nextLine();

            String result = isBalanced(s);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
