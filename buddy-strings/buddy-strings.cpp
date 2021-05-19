class Solution {
public:
    bool buddyStrings(string a, string b) {
        
        vector<int> ct(26, 0);
        if(a.size() != b.size())
            return false;
        if(a==b) {
            for(char c : a) {
                if(ct[c-'a']++)
                    return true;
            }
            return false;
        }
        string diffa, diffb;
        for(int i=0; i<a.size(); i++) {
            if(a[i]!=b[i]) {
                if(diffa.size()>2)
                    return false;
                diffa.append(1, a[i]);
                diffb.append(1, b[i]);
            }
        }
        if(diffa.size()==2 && 
           diffa[0]==diffb[1] && diffa[1]==diffb[0])
            return true;
        return false;
    }
};