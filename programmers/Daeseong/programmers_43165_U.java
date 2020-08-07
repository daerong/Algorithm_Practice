//solution
//    - number의 원소별로 -, +를 하여 더하는 경우의 수라고 볼 수 있다.
//    - target이 주어지면 모든 수의 합이 이와 같으면 되므로 target - sum이 0이면 합이 같다고 볼 수 있다.
//    - 모든 수의 부호를 반대로 하면 sum의 부호가 바뀌므로 아래의 수식을 사용했다.
//    - index가 끝으로 이동하면서 target의 값이 target + numbers[index]로 업데이트 된다.
//    - 이때 마지막에 0이 되면 결과값을 1증가시킨다.

class Solution {
    int answer;
    public int solution(int[] numbers, int target) {
        answer = 0;

        compare(numbers, target, 0);

        return answer;
    }

    private void compare(int[] numbers, int target, int index) {
        if (index == numbers.length) {
            if (target == 0) answer += 1;
            return;
        }

        int temp = numbers[index];

        compare(numbers, target + temp, index + 1);
        compare(numbers, target - temp, index + 1);
    }
}