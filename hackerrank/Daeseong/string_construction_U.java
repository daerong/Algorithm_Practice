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
        HashMap<String, Integer> m = new HashMap<>();
        int m_index = 0;
        String p = s.substring(0, 1);
        s = s.substring(1);
        answer += 1;
        while(s.length() != 0){
            if(p.length() > s.length()){
                return answer + s.length();
            }
            else if(p.equals(s.substring(0, p.length()))){
                if(p.length() == s.length()) return answer;
                p += s.substring(0, p.length());
                s = s.substring(p.length());
            }
            else{
                p += s.substring(0, 1);
                s = s.substring(1);
                answer += 1;
            }
        }

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
