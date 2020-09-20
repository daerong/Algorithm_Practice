//Solution
//- 다음을 구현하면 어렵지 않게 해결할 수 있다.
//- 1. 문자열 내에 숫자가 없으면 1을 더함
//- 2. 문자열 내에 소문자가 없으면 1을 더함
//- 3. 문자열 내에 대문자가 없으면 1을 더함
//- 4. 문자열 내에 특수문자가 없으면 1을 더함
//- 5-1. 더한 값과 문자열의 길이의 합이 6보다 작으면 6 - 문자열의 길이를 리턴한다.
//- 5-2. 6보다 크거나 같으면 더한 값을 리턴한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumNumber function below.
    static int minimumNumber(int n, String password) {
        // Return the minimum number of characters to make the password strong
        boolean one_number = false;
        boolean one_lower = false;
        boolean one_upper = false;
        boolean one_special = false;

        for(int i = 0; i < n; i++){
            char temp = password.charAt(i);
            if(temp >= '0' && temp <= '9') one_number = true;
            else if(temp >= 'a' && temp <= 'z') one_lower = true;
            else if(temp >= 'A' && temp <= 'Z') one_upper = true;
            else if(temp == '!' || temp == '@' || temp == '#' || temp == '$' || temp == '%' || temp == '^' || temp == '&' || temp == '*' || temp == '(' || temp == ')' || temp == '-' || temp == '+') one_special = true;
        }

        int answer = 0;
        if(!one_number) answer++;
        if(!one_lower) answer++;
        if(!one_upper) answer++;
        if(!one_special) answer++;

        if(answer + n < 6) return 6 - n;
        else return answer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String password = scanner.nextLine();

        int answer = minimumNumber(n, password);

        bufferedWriter.write(String.valueOf(answer));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
