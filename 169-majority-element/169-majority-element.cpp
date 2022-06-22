class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> m;
        int majority = ceil((float)nums.size()/2);
        for(auto num : nums) {
            m[num]++;
        };
        
        for(auto ele : m) {
            if (ele.second >= majority)
                return ele.first;
        }
        
        return -1;
    }
};