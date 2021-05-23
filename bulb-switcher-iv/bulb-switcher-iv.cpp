class Solution {
public:
    
    int minFlips(string target) {
        
        int len = target.length();
        string input = "";
        for(int i = 0; i < len; i++)
            input.append("0");
        
        // cout<<input<<" "<<target<<endl;
        
        if(input == target)
            return 0;
        
        int count = 0;
        for(int i = 0; i < len; i++)
        {
            int i1 = (input[i] - '0'), t1 = (target[i] - '0');
            i1 = (count % 2 == 0) ? i1 : (i1 == 1 ? 0 : 1);
            
            if(i1 != t1)
                count++;
        };
        
        return count;
    }
};