class Solution {
public:
    
    struct trieNode{
        vector<string> suggestions;
        trieNode* children[26];
        bool endOfWord;
        trieNode()
        {
            endOfWord = false;
            suggestions.clear();
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
        };
    };
    
    void insertToTrie(string &word, trieNode* root)
    {
        trieNode* curr = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(curr->children[word[i] - 'a'] == NULL)
            {
                curr->children[word[i] - 'a'] = new trieNode();
            };
            curr = curr->children[word[i] - 'a'];
            
            if(curr->suggestions.size() < 3)
            {
                curr->suggestions.push_back(word);
            };
        };
        curr->endOfWord = true;
    };
    
    vector<string> getWords(trieNode* root, int &len, string& word)
    {
        trieNode* curr = root;
        for(int i = 0; i < len; i++)
        {
            if(curr->children[word[i] - 'a'] == NULL)
                return {};
            curr = curr->children[word[i] - 'a'];
        };
        return curr->suggestions;
    };
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> out;
        trieNode* root = new trieNode();
        sort(products.begin(), products.end());
        
        for(auto product : products)
        {
            insertToTrie(product, root);
        };
        
        for(int i = 1; i <= searchWord.length(); i++)
        {
            vector<string> tmp = getWords(root, i, searchWord);
            out.push_back(tmp);
        };
        
        return out;
    }
};