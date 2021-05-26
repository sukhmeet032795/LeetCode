class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
        int size = 0;
        deque<char> d;
        map<char, int> m;
        
        for(int i = 0; i < word.length(); i++)
        {
            if(!d.empty() && d.back() > word[i])
            {
                d.clear();
                m.clear();
            };
            
            m[word[i]]++;
            d.push_back(word[i]);
            
            if(m.size() == 5){
                int s = d.size();
                size = max(size, s);
            }
        };
        return size;
    };
};