class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> arr = nums;
        int n = arr.size();
        
        if(n == 0 || n == 1)
            return;
        
        for(int i = 0; i < n; i++)
        {
            nums[(i+k)%n] = arr[i];
        }
    }
};