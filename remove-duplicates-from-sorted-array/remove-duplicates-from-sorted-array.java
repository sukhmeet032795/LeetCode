class Solution {
    public int removeDuplicates(int[] nums) {
        
        int vInd = 1;
        for(int cInd = 1; cInd < nums.length; cInd++) {
            if (nums[cInd] != nums[cInd - 1]) {
                nums[vInd++] = nums[cInd];
            }
        }
        return vInd;
    }
}