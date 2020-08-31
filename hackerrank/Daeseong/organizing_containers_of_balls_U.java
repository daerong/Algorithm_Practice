//Solution
//- Ball은 Bucket 간 상호교환만 가능하다. 따라서, Bucket 내부의 공 갯수는 변하지 않는다.
//- 그럼 같은 공을 각각 Bucket에 넣기 위해서는 각각의 공 갯수의 조합이 Bucket 안의 공의 수 조합과 일치해야한다.
//- 1. long 배열을 두개 선언해 하나는 각각의 공의 갯수를, 하나는 각 Bucket 안의 공의 수를 저장한다.
//- 2. Hashmap에 Key는 공의 수, value는 공의 수가 같은 것의 갯수를 저장한다. (각각 공의 갯수 배열)
//- 3. 이제는 Hashmap에서 하나씩 빼며 비교한다. (각각 Bucket의 공의 수 배열)
//- 3.1. Hashmap에 같은 수의 공이 없으면 Impossible을 리턴.
//- 3.2. Hashmap에 있는 값이 0보다 같거나 작으면 Impossible 리턴.
//- 3.3. 위 두 사항에 해당하지 않으면 Value 값을 1감소시킴.
//- 4. 3의 과정을 반복하며 return 하지 않았다면 가능한 경우로 보고 Possible을 리턴.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the organizingContainers function below.
    static String organizingContainers(int[][] container) {
        int n = container.length;
        long[] bucket = new long[n];
        long[] balls = new long[n];
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                balls[x] += container[y][x];
                bucket[y] += container[y][x];
            }
        }
        HashMap<Long, Integer> m = new HashMap<>();
        for(int i = 0; i < n; i++){
            if(m.containsKey(balls[i]))m.put(balls[i], m.get(balls[i]) + 1);
            else m.put(balls[i], 1);
        }
        for(int i = 0; i < n; i++){
            if(!m.containsKey(bucket[i])) return "Impossible";
            int num = m.get(bucket[i]);
            if(num <= 0) return "Impossible";
            m.put(bucket[i], num - 1);
        }

        return "Possible";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[][] container = new int[n][n];

            for (int i = 0; i < n; i++) {
                String[] containerRowItems = scanner.nextLine().split(" ");
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int j = 0; j < n; j++) {
                    int containerItem = Integer.parseInt(containerRowItems[j]);
                    container[i][j] = containerItem;
                }
            }

            String result = organizingContainers(container);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}