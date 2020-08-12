//Solution
//- Using Hash map
//- key를 String으로 하는 int map을 이용.
//- 배열에 카테고리별 품목갯수를 저장
//- 각 항목은 입지 않는 경우를 포함하여 곱을 통해 연산이 가능하다.
//- 하지만 주어진 문제에서 스파이는 최소한 한가지 옷을 입어야하므로 다음의 공식을 도출할 수 있다.
//- result = (n1 + 1)(n2 + 1)...(nn + 1) - 1

import java.util.Arrays;
import java.util.HashMap;

class Solution {
    static HashMap<String, Integer> m = new HashMap<>();

    public int solution(String[][] clothes) {
        int[] category = new int[clothes.length + 1];
        Arrays.fill(category, 1);
        int category_index = 0;

        for(int i = 0; i < clothes.length; i++){
            String str = clothes[i][1];
            if(!m.containsKey(str)) m.put(str, category_index++);
            int cate = m.get(str);
            category[cate] += 1;
        }

        int answer = 1;
        for(int i = 0; i < category_index; i++){
            answer *= category[i];
        }

        answer -= 1;

        return answer;
    }
}