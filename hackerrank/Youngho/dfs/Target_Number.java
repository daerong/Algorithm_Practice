//link : https://programmers.co.kr/learn/courses/30/lessons/43165?language=java
//난이도 : medium hard

class Solution {
    public int solution(int[] numbers, int target) {
        int answer = 0;
        answer = dfs(numbers, 0, 0, target);
        return answer;
    }
        
    private int dfs(int[] arr, int len, int sum, int target){
            if(len == arr.length){
                if(sum == target)
                    return 1;
                return 0;
            }
            return dfs(arr, len+1, sum + arr[len], target) + 
                   dfs(arr, len+1, sum + arr[len]*-1, target);         
    }
}

//ref : https://sas-study.tistory.com/248
