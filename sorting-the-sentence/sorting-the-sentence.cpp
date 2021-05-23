class Solution {
public:
    string sortSentence(string s) {
        
        vector<string> str(9, "");
        stringstream ss(s);
        string tmp;

        while(getline(ss, tmp, ' '))
        {
            int ind = (tmp[tmp.length() - 1] - '0');
            tmp.erase(tmp.end() - 1);
            str[ind-1] = tmp;
        };

        string out = "";
        for(int i = 0; i < 9; i++)
        {
            if(str[i] != "")
            {
                out += str[i];
                out += " ";
            }
        }
        out.erase(out.end() - 1);
        return out;
    }
};