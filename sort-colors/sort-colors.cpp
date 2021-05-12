class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int len = nums.size();
        int start = 0, mid = 0, end = len-1;
        
        while(mid <= end)
        {
            switch(nums[mid])
            {
                case 0:
                    {
                        swap(nums[start], nums[mid]);
                        start++;
                        mid++;
                    }
                    break;
                case 1:
                    {
                        mid++;
                    }
                    break;
                case 2:
                    {
                        swap(nums[mid], nums[end]);
                        end--;
                    }
                    break;
            }
        }
    }
};