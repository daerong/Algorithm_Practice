//Solution
//- Using DFS.
//- should to do visit check. If you don't, it should be occur time out error.


import java.util.Arrays;

class Solution {
    int last;
    int[] nums_copy;
    boolean[] visited;
    boolean result = false;

    public boolean canJump(int[] nums) {
        nums_copy = new int[nums.length];
        visited = new boolean[nums.length];
        Arrays.fill(visited, false);
        System.arraycopy(nums, 0, nums_copy, 0, nums.length);

        last = nums.length - 1;
        dfs(0);
        return result;
    }

    public void dfs(int step) {
        if(step == last){
            result = true;
            return;
        }
        if(step > last) return;
        if(visited[step]) return;
        visited[step] = true;

        for(int i = 1; i <= nums_copy[step]; i++){
            dfs(step + i);
        }
    }
}