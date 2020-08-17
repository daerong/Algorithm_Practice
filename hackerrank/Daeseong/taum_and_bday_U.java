//Solution
//- 검은색과 흰색 선물상자를 포장하는 최소비용을 구하는 문제
//- 색상을 변경하는 금액 z가 주어지므로 이를 고려해야한다.
//- bc > wc 인 경우, wc + z 비용이 bc보다 작을 경우 이를 곱해주면 된다.
//- 주어진 범위의 크기가 int 형보다 크므로 long 형을 선언하여 연산하도록 하자.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'taumBday' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER b
     *  2. INTEGER w
     *  3. INTEGER bc
     *  4. INTEGER wc
     *  5. INTEGER z
     */

    public static long taumBday(int b, int w, int bc, int wc, int z) {
        // Write your code here

        long result;
        long l_b = b;
        long l_w = w;
        long l_bc = bc;
        long l_wc = wc;
        long l_z = z;

        if(l_bc < l_wc){
            if(l_bc + l_z < l_wc) result = l_b * l_bc + l_w * (l_bc + l_z);
            else result = l_b * l_bc + l_w * l_wc;
        }else{
            if(l_wc + l_z < l_bc) result = l_b * (l_wc + l_z) + l_w * l_wc;
            else result = l_b * l_bc + l_w * l_wc;
        }

        return result;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        for (int tItr = 0; tItr < t; tItr++) {
            String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            int b = Integer.parseInt(firstMultipleInput[0]);

            int w = Integer.parseInt(firstMultipleInput[1]);

            String[] secondMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            int bc = Integer.parseInt(secondMultipleInput[0]);

            int wc = Integer.parseInt(secondMultipleInput[1]);

            int z = Integer.parseInt(secondMultipleInput[2]);

            long result = com.company.Result.taumBday(b, w, bc, wc, z);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedReader.close();
        bufferedWriter.close();
    }
}
