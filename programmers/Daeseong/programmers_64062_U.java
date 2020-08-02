//Solution
//- Binary Search.
//- 건너가는 사람 수를 검색대상으로 두고
//- 배열의 최대 최소 step 수를 초기 이분 배열의 검색범위로 한다.
//- 매회 두 수의 중간으로 건널 수 있는 지를 체크하고
//- 1. 건널 수 있다면 건너지 못하는 절반의 경우를 버리고
//- 2. 건널 수 없다면 건널 수 있는 절반의 경우를 버린다.

class Solution {
    public int solution(int[] stones, int k) {

        int start = Integer.MIN_VALUE;
        int end = Integer.MAX_VALUE;

        for (int stone : stones) {
            start = Math.min(start, stone);
            end = Math.max(end, stone);
        }

        int step;
        while(start <= end){
            step = (start + end) / 2;
            if(can_jump(step, k, stones)){
                start = step + 1;
            }else{
                end = step - 1;
            }
        }

        return start;
    }

    public boolean can_jump(int step, int k, int[] stones) {
        int cnt = 0;
        for (int stone : stones) {
            if (stone - step <= 0) cnt++;
            else cnt = 0;
            if (cnt >= k) return false;
        }

        return true;
    }
}