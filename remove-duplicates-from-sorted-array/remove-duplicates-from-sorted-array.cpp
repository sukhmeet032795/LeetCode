class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int vInd = 1;
        for(int cInd = 1; cInd < nums.size(); cInd++) {
            if (nums[cInd] != nums[cInd - 1]) {
                nums[vInd++] = nums[cInd];
            }
        }
        return vInd;
    }
};