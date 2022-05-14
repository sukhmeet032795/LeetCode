class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) {
            return false;
        }
        
        if (x == 0) {
            return true;
        }
        
        vector<int> nums;
        while(x != 0) {
            nums.push_back(x % 10);
            x = x / 10;
        }
        
        for(int i = 0, j = (nums.size() - 1); i < j; i++, j--){
            if (nums[i] != nums[j])
                return false;
        }
        return true;
    }
};