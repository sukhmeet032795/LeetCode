class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        map<int, int> m;
        int output = 0;
        
        for(int i = 0; i < time.size(); i++)
        {
            int tmp = time[i] % 60;
            
            if (m.find((60 - tmp) % 60) != m.end())
                output += m[(60 - tmp) % 60];
            
            m[tmp]++;
        }
        
        return output;
    }
};