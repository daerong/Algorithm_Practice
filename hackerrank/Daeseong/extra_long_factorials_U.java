//Solution
//- Using the BigInteger class.
//- When you use that, you should to use add(), subtract(), mumtiply(), divide()

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the extraLongFactorials function below.
    static void extraLongFactorials(int n) {
        BigInteger result = BigInteger.ONE;

        for (int i = 0; i < n; i++) {
            result = result.multiply(BigInteger.valueOf(i + 1));
        }

        System.out.println(result);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        extraLongFactorials(n);

        scanner.close();
    }
}