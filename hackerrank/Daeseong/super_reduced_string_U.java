//Solution
//- 인접 중복 문자를 제거하는 함수를 만들면 된다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the superReducedString function below.
    static String superReducedString(String s) {
        StringBuffer buff = new StringBuffer(s);
        for(int i = buff.length() - 1; i >= 0; i--){
            int j = i + 1;
            if(j >= buff.length()) continue;

            if(buff.charAt(i) == buff.charAt(j)) {
                buff.delete(i, j + 1);
            }
        }

        if(buff.length() == 0) return "Empty String";
        return String.valueOf(buff);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = superReducedString(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}