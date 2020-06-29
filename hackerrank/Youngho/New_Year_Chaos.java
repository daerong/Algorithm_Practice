//link : https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays&isFullScreen=true
//time : 2 hours (매우 어려움)
//type : sorting 인데 무한루프 전략이 필요함

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static void minimumBribes(int[] q) {
        int len = q.length;
        //idea
        for(int i=0; i<len; i++){
            if(q[i]-(i+1)>2){
                System.out.println("Too chaotic");
                return;
            }
        }

        int result = 0;
        //logic    i j c index
        //12537864 0 0 0 1
        //12537864 2 2 1 3
        //12357864 1 3 1 3
        //12357864 1 1 1 2
        //12357846 1 1 2 2
        
        for(int i=0; i<len; i++){
            if(q[i] != i+1){
                int index = i+1; //2번째부터 비교하기위해 첫 인자를 만들어줌
                for(int j=i; j<len; j++){
                    //스왑하려면 2번째부터 비교해야함
                    if(q[j] <= index){
                        int temp = q[j-1];
                        q[j-1] = q[j];
                        q[j] = temp;
                        result++;
                        i--; //i++를 감쇄시킴으로써 스왑할게 있으면 계속 반복시켜서 맨 앞으로 위치시킴(진짜 비기)
                    }

                }
            }
        }
        System.out.println(result); 
    }
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] q = new int[n];

            String[] qItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int qItem = Integer.parseInt(qItems[i]);
                q[i] = qItem;
            }

            minimumBribes(q);
        }

        scanner.close();
    }
}
