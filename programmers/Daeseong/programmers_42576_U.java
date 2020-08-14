//Solution
//- Using HashMap.
//- 완주한 인원은 항상 모든 선수에 비해 1이 작다.
//- 이름이 같은 선수가 있으므로 해시맵 외에 동일 이름의 수를 저장할 배열을 만듦.
//- 1. 완주 인원을 해시맵에 넣는다. 해시 값에는 index를 넣는다. 0~N
//- 2. 배열에는 해당하는 이름을 가진 사람의 명수를 기록한다. 매번 1씩 증가시킴.
//- 3. 참가 인원을 한명씩 제외한다. 다음에 경우 결과를 구하고 반복을 종료한다.
//    - 3-1. HashMap에 없는 선수가 있는 경우.
//    - 3-2. 해당 인원수가 음수가 된 경우.

import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> m = new HashMap<>();
        int[] mans = new int[completion.length];
        int man_index = 0;
        for(int i = 0; i < completion.length; i++){
            if(m.containsKey(completion[i])){
                mans[m.get(completion[i])] += 1;
            }else{
                m.put(completion[i], man_index);
                mans[man_index] = 1;
                man_index++;
            }
        }

        String answer = "";
        for(int i = 0; i < completion.length; i++){
            if(m.containsKey(participant[i])){
                man_index = m.get(participant[i]);
                mans[man_index] -= 1;
                if(mans[man_index] < 0) {
                    answer = participant[i];
                    break;
                }
            }else{
                answer = participant[i];
                break;
            }
        }

        return answer;
    }
}