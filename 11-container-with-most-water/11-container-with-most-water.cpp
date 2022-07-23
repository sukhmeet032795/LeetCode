class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int len = height.size(), left = 0, right = (len - 1), Max = 0;
        
        while(left < right) {
            
            Max = max(Max, min(height[left], height[right]) * (right - left));
            
            if (height[left] < height[right])
                left++;
            else 
                right--;
        };
        return Max;
    };
};