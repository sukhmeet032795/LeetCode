class Solution {
public:
    bool checkRecord(string s) {
        
        bool isAbsent = false, isLate = false;
        int count = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'L')
            {
                isLate = true;
                count++;
                continue;
            }
            
            if(isLate)
            {
                if(count >= 3)
                    return false;
                isLate = false;
                count = 0;
            }
            
            if(s[i] == 'A')
            {
                if(isAbsent)
                    return false;
                isAbsent = true;
            };
        };
        
        if(isLate)
        {
            if(count >= 3)
                return false;
            isLate = false;
            count = 0;
        }
        
        return true;
    }
};