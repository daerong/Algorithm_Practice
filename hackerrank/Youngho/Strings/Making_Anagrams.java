link : https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
time : 실패 0202.07.01

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static int makeAnagram(String a, String b) {
        //문자열을 문자로 쪼개고 문자를 사전화 하려면 정수를 카운트 해야하니 정수형 배열을 생성한다.
        //길이가 26인 이유는 알파벳의 개수(사전만들기)
        int [] alphabet = new int[26];
        int sum = 0;
        //foreach문을 사용하고 문자열의 각각은 문자니까 toCharArray()를 쓴다.
        for(char c : a.toCharArray()){
            //count up, a에 있는건 전부 카운트업 한다. 
            //각 문자의 수를 2중루프 돌며 구할 필요도 없다.
            alphabet[c - 'a']++;    
        }
        for(char c : b.toCharArray()){
            //count down, 없는건 안세고 있는것만 감소시킨다.
            alphabet[c - 'a']--;    
        }
        for(int i : alphabet){
            sum += Math.abs(i); // 음수가 있을 수 있으니 절대값을 계산한다.
        }
        return sum;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String a = scanner.nextLine();

        String b = scanner.nextLine();

        int res = makeAnagram(a, b);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

