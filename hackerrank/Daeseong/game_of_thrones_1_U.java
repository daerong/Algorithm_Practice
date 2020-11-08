//Solution
//- 알파벳 갯수가 홀수인 게 2개이면 "NO"를 출력하게 했는데 맞았다.
//- 1. Hashmap에 각 알파벳에대한 index를 지정한다. ex a = 1, z = 25
//- 2. 문자열 s의 각 문자의 갯수를 cnt[] 배열에 저장한다.
//- 3. 배열을 순회하며 홀수가 두개인지를 체크한다.
//- 3.1. 홀수가 두개이면 "NO"를 출력.
//- 3.2. 홀수가 두개 미만이면 "YES"를 출력.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the gameOfThrones function below.
    static String gameOfThrones(String s) {
        int[] cnt = new int[26];
        Arrays.fill(cnt, 0);
        HashMap<Character, Integer> m = new HashMap<>();
        for(int i = 0; i < 26; i++) m.put((char) ('a' + i), i);
        for(int i = 0; i < s.length(); i++) cnt[m.get(s.charAt(i))] += 1;
        boolean is_reverse = false;
        for(int i = 0; i < 26; i++){
            if(is_reverse){
                if(cnt[i] % 2 == 1) return "NO";
            }else{
                if(cnt[i] % 2 == 1) is_reverse = true;
            }
        }

        return "YES";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = gameOfThrones(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
