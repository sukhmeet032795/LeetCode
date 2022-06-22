class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int len = nums.size(), cInd = 0, zInd = 0;
        while(cInd < len) {
            if (nums[cInd] != 0) {
                nums[zInd++] = nums[cInd];
            }
            cInd++;
        }
        
        while(zInd < len) {
            nums[zInd++] = 0;
        }
    }
};