class WordDictionary {
public:
    struct node{
        char c;
        bool endOfWord;
        node* children[26];
        node(char c1) : c(c1), endOfWord(false)
        {
            for(int i = 0; i < 26; i++)
                children[i] = NULL;
        };
    };
    
    node* trie = NULL;
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new node('\0');
    };
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        
        node* tmp = trie;
        for(int i = 0; i < word.length(); i++)
        {
            if(tmp->children[word[i] - 'a'] == NULL)
                tmp->children[word[i] - 'a'] = new node(word[i]);
            tmp = tmp->children[word[i] - 'a'];
        }
        tmp->endOfWord = true;
    };
    
    bool search(string word, int ind, node* tmp)
    {
        if(tmp == NULL)
            return false;
        
        if(ind == word.length())
            return (tmp->endOfWord ? true : false);
        
        bool check = false;
        if(word[ind] == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(tmp->children[i] != NULL)
                {
                    check = check || search(word, ind+1, tmp->children[i]);
                }
                
                if(check)
                    break;
            }
        }
        else
        {
            if(tmp->children[word[ind] - 'a'] == NULL)
                return false;
            check = check || search(word, ind+1, tmp->children[word[ind] - 'a']);
        }
        
        return check;
    };
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        if(word.length() == 0)
            return false;
        return search(word, 0, trie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */