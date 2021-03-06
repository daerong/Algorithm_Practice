//link : https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
//try : 2times
//times : 2hour

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the jumpingOnClouds function below.
    static int jumpingOnClouds(int[] c) {
        int len = c.length;
        int count = 0;
//0 0 0 1 1 0
//i c
//1 1
//3 2
//4

        for(int i=0; i<len; i++){
            if(i == len-1)
                break;
            if(i+1<len && c[i+1] == 0){
                if(i+2<len && c[i+2] == 0){
                    count++;
                    ++i;
                }else{
                    count++;
                }
            }
            if(i+1<len && c[i+1] == 1){
                if(i+2<len && c[i+2] == 0){
                    count++;
                    ++i;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
    

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] c = new int[n];

        String[] cItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int cItem = Integer.parseInt(cItems[i]);
            c[i] = cItem;
        }

        int result = jumpingOnClouds(c);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
 
