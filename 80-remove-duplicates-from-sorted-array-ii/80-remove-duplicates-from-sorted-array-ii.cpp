class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int len = nums.size();
        int start = 0;
        map<int, int> m;
        
        for(int i = 0; i < len; i++) {
            if(m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
                nums[start++] = nums[i];
            }
            else if (m.find(nums[i]) != m.end() && m[nums[i]] < 2) {
                m[nums[i]]++;
                nums[start++] = nums[i];
            }
        }
        
        return start;
    }
};