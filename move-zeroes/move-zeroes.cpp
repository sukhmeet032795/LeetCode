class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zInd = 0, cInd = 0, len = nums.size();
        while (cInd < len) {
            if (nums[cInd] != 0) {
                nums[zInd++] = nums[cInd];
            }
            cInd++;
        }
        
        while (zInd < len) {
            nums[zInd++] = 0;
        }
    }
};