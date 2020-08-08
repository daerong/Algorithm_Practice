//link : https://programmers.co.kr/learn/courses/30/lessons/43165?language=java

class Solution {
    public int solution(int[] numbers, int target) {
        int answer = 0;
        answer = dfs(numbers, 0, 0, target);
        return answer;
        
        private int dfs(int[] arr, int len, int sum, int target){
            if(len == arr.length){
                if(sum == target){
                    return 1;
                }else{
                    return 0;
                }
            }
            dfs(arr[i], len++);
            dfs(arr[i]*-1, len++);            
         
        
    }
}

//ref : https://sas-study.tistory.com/248
