class Solution {
public:
    int minSwaps(vector<int>& data) {
        
        int len = data.size();
        int maxOnes = 0, currOnes = 0;
        
        for(int i = 0; i < len; i++)
            if(data[i] == 1)
                maxOnes++;
        
        int x = maxOnes;
        for(int i = 0; i < x; i++)
        {
            if(data[i] == 1)
                currOnes++;
        }
        
        int nOnes = currOnes;
        for(int i = 1; i <= (len - x); i++)
        {
            currOnes -= data[i-1];
            currOnes += data[i+x-1];
            
            if(currOnes > nOnes)
                nOnes = currOnes;
        }
        
        int zeros = x - nOnes;
        return zeros;
    }
};