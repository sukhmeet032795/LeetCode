class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> out;
        set <vector<int>> us;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        
        for(int i = 0; i < (len-2); i++) {
            int j = (i + 1), k = (len - 1);
                        
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0 && us.find({nums[i], nums[j], nums[k]}) == us.end()) {
                    out.push_back({nums[i], nums[j], nums[k]});
                    us.insert({nums[i], nums[j], nums[k]});
                };
                
                if (sum > 0)
                    k--;
                else 
                    j++;
            };
        };
        
        return out;
    }
};
