class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n == 0)
            return true;
        
        int len = flowerbed.size();
        if(len == 1 && flowerbed[0] == 0)
            return true;
        
        for(int i = 0; i < len; i++) {
            
            if(n == 0)
                return true;
            
            if(flowerbed[i] == 1)
                continue;
            else {
                if((i-1) >= 0 && (i+1) < len && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
                else if((i-1) >= 0 && flowerbed[i-1] == 0 && (i+1) == len) {
                    flowerbed[i] = 1;
                    n--;
                }
                else if((i+1) < len && flowerbed[i+1] == 0 && (i-1) < 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        
        if(n == 0)
            return true;
        
        return false;
    }
};