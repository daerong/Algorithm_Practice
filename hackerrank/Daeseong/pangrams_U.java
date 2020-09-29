//Solution
//- 알파벳이 전부 등장하는 경우 pangram, 그렇지 않은 경우 not pangram을 return

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the pangrams function below.
    static String pangrams(String s) {
        boolean[] alphabet = new boolean[26];
        Arrays.fill(alphabet, false);
        char[] s_arr = s.toCharArray();
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s_arr[i] >= 'A' && s_arr[i] <= 'Z'){
                if(!alphabet[s_arr[i] - 'A']) {
                    alphabet[s_arr[i] - 'A'] = true;
                    cnt++;
                }
            }else if(s_arr[i] >= 'a' && s_arr[i] <= 'z'){
                if(!alphabet[s_arr[i] - 'a']) {
                    alphabet[s_arr[i] - 'a'] = true;
                    cnt++;
                }
            }
        }

        if(cnt == 26) return "pangram";
        else return "not pangram";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = pangrams(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
