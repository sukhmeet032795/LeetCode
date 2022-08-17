class Solution {
public:
    bool isValid(string s) {
        
        int len = s.length();
        stack<char> s1;
        
        for(auto itr : s) {
            
            if (itr == '(' || itr == '[' || itr == '{') {
                s1.push(itr);
            } else {
                
                if (s1.empty())
                    return false;
                
                if (s1.top() == '(' && itr == ')')
                    s1.pop();
                else if (s1.top() == '{' && itr == '}')
                    s1.pop();
                else if (s1.top() == '[' && itr == ']')
                    s1.pop();
                else
                    return false;
            }
        };
        
        if (!s1.empty())
            return false;
        
        return true;
    }
};