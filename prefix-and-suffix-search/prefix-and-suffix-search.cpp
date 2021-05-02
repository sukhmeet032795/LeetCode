class WordFilter {
public:
    
    struct trieNode{
        set<string> words;
        trieNode* children[26];
        trieNode(){
            for(int i = 0; i < 26; i++)
                children[i] = NULL;
        };
    };
    
    trieNode* trie = NULL;
    unordered_map<string, int> orgWords;
    
    void insertInTrie(string word)
    {
        trieNode* curr = trie;
        for(int i = 0; i < word.length(); i++)
        {
            if(curr->children[word[i] - 'a'] == NULL)
            {
                trieNode *tmp = new trieNode();
                curr->children[word[i] - 'a'] = tmp;
            };
            curr = curr->children[word[i] - 'a'];
            curr->words.insert(word);
        };
    };
    
    set<string> getWords(string prefix)
    {
        trieNode* curr = trie;
        for(int i = 0; i < prefix.length(); i++)
        {
            if(curr->children[prefix[i] - 'a'] == NULL)
            {
                return {};
            };
            curr = curr->children[prefix[i] - 'a'];
        };
        return curr->words;
    };
    
    WordFilter(vector<string>& words) {
        
        trie = new trieNode();
        for(int i = 0; i < words.size(); i++)
        {
            if(orgWords.find(words[i]) == orgWords.end())
            {
                insertInTrie(words[i]);
            }
            orgWords[words[i]] = i;
        };
    }
    
    int f(string prefix, string suffix) {
        
        set<string> words = getWords(prefix);
        int ind = 0, lenS = suffix.length();
        string ans = "";
        
        // cout<<prefix<<" "<<suffix<<endl;
        // for(auto itr : words)
        // {
        //     cout<<itr<<" ";
        // }
        // cout<<endl;
        
        // cout<<prefix<<" "<<suffix<<endl;
        for(auto itr : words)
        {
            int tmpL = itr.length();
            // cout<<itr<<endl;
            // if(tmpL >= lenS)
            // {
            string tmp = itr.substr(tmpL - lenS, lenS);
            // cout<<tmp<<endl;
            if(tmp == suffix)
            {
                if(ans.length() < itr.length())
                {
                    ans = itr;
                    ind = orgWords[itr];
                }
                else if(ans.length() == itr.length() && ind < orgWords[itr])
                {
                    ans = itr;
                    ind = orgWords[itr];
                }
            // }
            }
        }
        return (ans == "") ? -1 : ind;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */