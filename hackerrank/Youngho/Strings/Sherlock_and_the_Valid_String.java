//link : https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings&h_r=next-challenge&h_v=zen
//try : 1
//비고 : 11개 okay, but 4개 case 예외 발생

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the isValid function below.
    static String isValid(String s) {
        int count = 0;
        boolean exception = false;
        int len = s.length();
        String result = "";
        int []arr = new int[len];

        for(int i=0; i<len; i++){
            arr[s.charAt(i) - 'a'] ++;
        }
        count = arr[0];
        for(int i=0; i<len-1; i++){
            //index 값이 0인 것은 제외한다.
            if(arr[i] != 0 && arr[i+1] != 0){
                //절대값 차가 1을 넘으면 stop
                if(Math.abs (arr[i]-arr[i+1]) > 1){
                    return "NO";
                }
                //뒤의 차가 1이면 1번은 허용
                else if(arr[i+1]-arr[i] == 1 && exception == false){
                    exception = true;
                    //실제 값을 줄여야 다음번 비교때, "뒤의 값이 더 작은 경우" 조건에 부합하지 않음
                    arr[i+1] --; 
                }
                //이미 한번 허용했으면 stop
                else if(arr[i+1]-arr[i] == 1 && exception == true){
                    return "NO";
                }
                //뒤의 값이 더 작은 경우
                else if(arr[i+1]-arr[i] < 0){
                    return "NO";
                }
            }
        }

    return "YES";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = isValid(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
