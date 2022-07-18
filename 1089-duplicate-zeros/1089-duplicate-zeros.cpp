class Solution {
public:
    void duplicateZeros(vector<int>& nums) {
        
        int len = nums.size(), index = 0;
        vector<int> arr(len);
        
        for(int i = 0; i < len; i++) {
            if (index == len)
                break;
            if (nums[i] != 0) {
                arr[index++] = nums[i];
            } else {
                arr[index++] = 0;
                if (index == len)
                    break;
                arr[index++] = 0;
            }
        };
        nums = arr;
    }
};