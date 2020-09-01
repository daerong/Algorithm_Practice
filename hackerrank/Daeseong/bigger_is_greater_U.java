//Solution
//- 다음과 같은 방식으로 해결할 수 있다.
//- 0. 주어진 문자열의 길이가 1인 경우, no answer를 리턴한다.
//- 1. 사전순으로 앞에 있는 문자가 뒤에 있는 문자보다 크다.
//- 2. 문자열의 뒤에서부터 두 문자를 비교한다.
//- 2-1. 두 문자 중 앞에 문자가 더 작은 경우, 3으로 이동한다.
//- 2-2. 그 외의 경우 앞으로 계속 이동한다.
//- 2-3. 가장 앞까지 이동한 경우, no answer를 리턴한다.
//- 3. 다음과 같은 방식으로 문자열을 구성한다.
//- 3-1. 2-1의 작은 문자열의 위치를 n이라 할 때, n앞쪽은 그대로 유지한다.
//- 3-2. n뒤쪽에 있는 문자 중 가장 작은 문자를 찾아 n위치와 치환한다.
//- 3-3. n뒤쪽은 오름차순 정렬한다.(a가 앞 z가 뒤)
//- 다음과 같은 실수에 주의하자.
//- 1. charAt를 반복적으로 사용하면 가독성이 떨어져 실수할 수 있다.
//    - toCharArray()를 사용해 char 배열로 만들어 사용하자.
//- 2. MaxValue가 포함된 Arrays.sort()를 사용할 때, 같은 문자가 들어가는 문제가 발생했다.
//    - Alphabet 배열에 문자 갯수를 저장해 순서대로 출력해 해결했다.

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static HashMap<Character, Integer> cti = new HashMap<>();
    static HashMap<Integer, Character> itc = new HashMap<>();

    // Complete the biggerIsGreater function below.
    static String biggerIsGreater(String w) {
        int L = w.length();
        if(L == 1) return "no answer";
        String answer;
        int[] alphabet = new int[26];
        char[] target = w.toCharArray();
        for(int i = L - 2; i >= 0; i--) {
            alphabet[cti.get(target[i + 1])] += 1;
            if(target[i] < target[i + 1]) {
                alphabet[cti.get(target[i])] += 1;
                if(i == 0) answer = "";
                else answer = w.substring(0, i);
                for(int k = cti.get(target[i]) + 1; k < 26; k++){
                    if(alphabet[k] == 0) continue;
                    answer += itc.get(k);
                    alphabet[k] -= 1;
                    break;
                }
                for(int r = 0; r < 26; r++){
                    if(alphabet[r] == 0) continue;
                    char temp = itc.get(r);
                    for(int rotate = alphabet[r]; rotate > 0; rotate--){
                        answer += temp;
                    }
                }
                return answer;
            }
        }
        return "no answer";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int temp = 0;
        for(char c = 'a'; c <= 'z'; c++){
            cti.put(c, temp);
            itc.put(temp, c);
            temp++;
        }

        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int T = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int TItr = 0; TItr < T; TItr++) {
            String w = scanner.nextLine();

            String result = biggerIsGreater(w);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}