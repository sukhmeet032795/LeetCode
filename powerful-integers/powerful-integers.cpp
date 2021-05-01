class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        int Max = max(x, y);
        
        vector<int> out1 = {1};
        vector<int> out2 = {1};
        
        if(x != 1)
        {
            for(int i = 1; i < bound; i++)
            {
                int tmp = pow(x, i);
                if(tmp > INT_MAX || tmp > bound)
                    break;
                out1.push_back(tmp);
            }
        }
        
        if(y != 1)
        {
            for(int i = 1; i < bound; i++)
            {
                int tmp = pow(y, i);
                if(tmp > INT_MAX || tmp > bound)
                    break;
                out2.push_back(tmp);
            }
        }
        
        unordered_set<int> s;
        
        for(int i = 0; i < out1.size(); i++)
        {
            for(int j = 0; j < out2.size(); j++)
            {
                if((out1[i] + out2[j]) >= INT_MAX || (out1[i] + out2[j]) > bound)
                    break;
                s.insert(out1[i] + out2[j]);
            }
        }
        
        return vector<int>(s.begin(), s.end());
    }
};
