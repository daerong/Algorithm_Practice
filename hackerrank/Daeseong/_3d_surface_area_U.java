//Solution
//- 겉넓이를 구하는 문제, 다음의 규칙이 적용된다.
//- 1. 육면체의 면의 갯수는 6이다.
//- 2. 총 면의 갯수는 육면체의 갯수 * 6이다.
//- 3. 맞닿은 면의 갯수당 총 면의 갯수는 2씩 감소한다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the surfaceArea function below.
    static int surfaceArea(int[][] A) {
        int result = 0;
        int mX = A[0].length;
        int mY = A.length;
        for(int y = 0; y < mY; y++){
            for(int x = 0; x < mX; x++){
                switch (A[y][x]){
                    case 1:
                        result += 6;
                        break;
                    default:
                        result += 10 + 4 * (A[y][x] - 2);
                }
            }
        }
        for(int y = 0; y < mY; y++){
            for(int x = 1; x < mX; x++){
                result -= 2 * Math.min(A[y][x - 1], A[y][x]);
            }
        }
        for(int x = 0; x < mX; x++){
            for(int y = 1; y < mY; y++){
                result -= 2 * Math.min(A[y - 1][x], A[y][x]);
            }
        }

        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] HW = scanner.nextLine().split(" ");

        int H = Integer.parseInt(HW[0]);

        int W = Integer.parseInt(HW[1]);

        int[][] A = new int[H][W];

        for (int i = 0; i < H; i++) {
            String[] ARowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < W; j++) {
                int AItem = Integer.parseInt(ARowItems[j]);
                A[i][j] = AItem;
            }
        }

        int result = surfaceArea(A);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}