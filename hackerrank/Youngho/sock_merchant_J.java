//link : https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
//try : 1
//time : 15m

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the sockMerchant function below.
    static int sockMerchant(int n, int[] ar) {
        int len = ar.length;
        boolean check[] = new boolean[len];
        //init
        for (int i=0; i<check.length; i++){
            check[i] = false;
        }
        int count = 0;

        for(int i=0; i<len-1; i++){
            //이미 짝이면 패스
            if(check[i] == true)
                continue;
            for(int j=i+1; j<len; j++){
                //이미 짝이면 패스
                if(check[j] == true)
                    continue;
                //짝인 경우
                if(ar[i] == ar[j]){
                    count++;
                    check[i] = true;
                    check[j] = true;
                    break;
                }
            }
            //짝이 없으면 폐기
            check[i] = true;
        }
        return count;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] ar = new int[n];

        String[] arItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = sockMerchant(n, ar);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
