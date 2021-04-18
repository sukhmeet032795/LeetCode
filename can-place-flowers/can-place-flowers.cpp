class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int size = flowerbed.size(), count = 0; 
        
        if(size == 1 && flowerbed[0] == 0)
            return true;
        
        for(int i = 0; i < size; i++)
        {
            if(i == 0 && flowerbed[i] == 0)
            {
                if((i+1) < size && flowerbed[i+1] == 0){
                    count++;
                    flowerbed[i] = 1;
                }
            }
            else if(i == (size - 1) && flowerbed[i] == 0)
            {
                if((i-1) >= 0 && flowerbed[i-1] == 0){
                    count++;
                    flowerbed[i] = 1;
                }
            }
            else if((i != 0 && (i+1) != size ) && flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] != 1)
            {
                count++;
                flowerbed[i] = 1;
            }
            // else
            //     cout<<i<<" party"<<endl;
        }
        
        if(count >= n)
            return true;
        return false;
    }
};