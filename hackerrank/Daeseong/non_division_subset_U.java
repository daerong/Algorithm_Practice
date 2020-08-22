//Solution
//- 집합을 이루는 성분 두개를 뽑아 더했을 때, k가 되지 않는 부분집합 중 가장 큰 부분집합의 원소 갯수를 구하는 문제.
//- 아래와 같이 접근했다.
//- 1. 모든 수를 k로 나누어 나머지를 구하고 arr[나머지]에 해당하는 값을 1증가시킨다.
//    최종적으로 arr 배열에는 나머지 갯수가 일치하는 원소의 갯수가 저장된다.
//- 2. 두 수의 합이 0 또는 k가 되는 경우를 피해야 하므로 다음의 규칙을 따른다.
//    2-1. k가 짝수인 경우 나머지가 k/2인 두가지를 합하면 k가 된다. 따라서 k/2 성분은 최대 한개만 추가할 수 있다.
//    2-2. 나머지가 0인 두 수를 더해도 마찬가지 이므로 0 성분도 최대 한개만 추가할 수 있다.
//    2-3. 나머지가 n인 수와 k-n인 수 중에서 하나만 선택가능하므로 두 수의 최대값을 추가할 수 있다.


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'nonDivisibleSubset' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER k
     *  2. INTEGER_ARRAY s
     */

    public static int nonDivisibleSubset(int k, List<Integer> s) {
        // Write your code here
        int answer = 0;

        int N = s.size();
        int[] arr = new int[100];
        Arrays.fill(arr, 0);

        for(int i = 0; i < N; i++){
            arr[s.get(i) % k] += 1;
        }

        if(k%2 == 0) {
            for(int i = 1; i < k / 2; i++){
                answer += Math.max(arr[i], arr[k - i]);
            }
            if(arr[k/2] > 0) answer += 1;
        }
        else{
            for(int i = 1; i <= k / 2; i++){
                answer += Math.max(arr[i], arr[k - i]);
            }
        }

        if(arr[0] > 0) answer += 1;

        return answer;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int k = Integer.parseInt(firstMultipleInput[1]);

        String[] sTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> s = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int sItem = Integer.parseInt(sTemp[i]);
            s.add(sItem);
        }

        int result = com.company.Result.nonDivisibleSubset(k, s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}