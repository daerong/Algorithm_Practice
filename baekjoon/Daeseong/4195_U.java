//Solution
//- Map에서 키를 정수로 사용하여 속도를 높임.
//- Union-Find로 Parent 배열을 이용.
//- Find, getParent 함수에서 다시 찾는 것을 방지하기 위해 값 업데이트 필요.

package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;

class Main {
    static HashMap<String, Integer> m = new HashMap<>();
    static int[] parent;
    static int[] friends;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   // nextToken()

        int TC = Integer.parseInt(br.readLine());           // 공백 구분자로 입력, Scanner보다 빠르다.
        for(int tc = 1; tc <= TC; tc++){
            int N = Integer.parseInt(br.readLine());
            int ARR_MAX = N * 2 ;
            parent = new int[ARR_MAX];
            friends = new int[ARR_MAX];
            Arrays.fill(friends, 1);            // 함수를 통해 initailize
            for(int i = 0; i < ARR_MAX; i++){
                parent[i] = i;
            }

            m.clear();

            String one, two;
            int index = 0;
            for(int n = 0; n < N; n++){
                StringTokenizer st = new StringTokenizer(br.readLine());                    // 공백 문자 제외
                one = st.nextToken();
                two = st.nextToken();
                if(!m.containsKey(one)) m.put(one, index++);
                if(!m.containsKey(two)) m.put(two, index++);

                System.out.println(Union(m.get(one), m.get(two)));
            }
        }
    }

    public static int Union(int one, int two) {
        one = getParent(one);
        two = getParent(two);

        if (one < two){
            parent[two] = one;
            friends[one] += friends[two];
            friends[two] = 1;
            return friends[one];
        }
        else if (one > two) {
            parent[one] = two;
            friends[two] += friends[one];
            friends[one] = 1;
            return friends[two];
        }

        return friends[two];
    }

    public static int getParent(int target) {
        if (target == parent[target]) return target;
        return parent[target] = getParent(parent[target]);
    }
}