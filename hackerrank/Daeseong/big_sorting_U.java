import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the bigSorting function below.
    static String[] bigSorting(String[] unsorted) {
        PriorityQueue<BigNum> pq = new PriorityQueue<>();
        for(int i = 0; i < unsorted.length; i++){
            pq.offer(new BigNum(unsorted[i].length(), unsorted[i]));
        }
        int index = 0;
        while (!pq.isEmpty()){
            BigNum temp = pq.poll();
            unsorted[index] = temp.str;
            index++;
        }

        return unsorted;
    }

    static class BigNum implements Comparable<BigNum>{
        int len;
        String str;

        public BigNum(int len, String str) {
            this.len = len;
            this.str = str;
        }

        @Override
        public int compareTo(BigNum o) {
            if (this.len > o.len) return 1;
            else if(this.len < o.len) return -1;
            else{
                for(int i = 0; i < o.len; i++){
                    if(this.str.charAt(i) > o.str.charAt(i)) return 1;
                    else if(this.str.charAt(i) < o.str.charAt(i)) return -1;
                }
                return 0;
            }
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String[] unsorted = new String[n];

        for (int i = 0; i < n; i++) {
            String unsortedItem = scanner.nextLine();
            unsorted[i] = unsortedItem;
        }

        String[] result = bigSorting(unsorted);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(result[i]);

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}