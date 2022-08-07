class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int min = INT_MAX;
            int mid = INT_MAX;
            for(auto n : nums)
            {
                if(n < min)
                {
                    min = n;
                }
                else if(n > min)
                {
                    if(mid < n)
                        return true;
                    mid = n;
                }
            }
            return false;
    }
};