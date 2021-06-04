class Solution {
public:
    string arrangeWords(string text) {
        
        map<int, string> m;
        stringstream ss(text);
        string tmp;
        bool check = true;
        while(getline(ss, tmp, ' '))
        {
            if(check == true)
            {
                tmp[0] = tolower(tmp[0]);
                check = false;
            }
            int len = tmp.length();
            if(m[len].length() == 0)
                m[len] = tmp;
            else
                m[len] = m[len] + " " + tmp;
        }
        
        text = "";
        for(auto itr : m)
        {
            text = text + itr.second + " "; 
        };
        m.clear();
        
        text.erase(text.end()-1);
        text[0] = toupper(text[0]);
        
        return text;
    };
};