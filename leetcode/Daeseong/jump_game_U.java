class Solution {
    int last;
    int[] nums_copy;
    boolean result = false;

    public boolean canJump(int[] nums) {
        nums_copy = new int[nums.length];
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

        for(int i = 1; i <= nums_copy[step]; i++){
            dfs(step + i);
        }
    }
}