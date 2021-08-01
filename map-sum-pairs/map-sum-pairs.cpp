class MapSum {
public:
    
    class trieNode{
        public:
            unordered_map<char, trieNode*> children;
            int sum;
            trieNode(){
                sum = 0;
                children.clear();
            };
    };
    
    /** Initialize your data structure here. */
    trieNode* trie = NULL;
    unordered_map<string, int> se;
    MapSum() {
        trie = new trieNode();
    }
    
    void change(string key, int oldV, int newV) {
        
        trieNode* curr = trie;
        for(int i = 0; i < key.length(); i++)
        {
            if(curr->children.find(key[i]) == curr->children.end())
            {
                curr->children[key[i]] = new trieNode();
            }
            curr = curr->children[key[i]];
            curr->sum -= oldV;
            curr->sum += newV;
        };
    };
    
    void insert(string key, int val) {
        
        if(se.find(key) != se.end())
        {
            change(key, se[key], val);
            se[key] = val;
        }
        else
        {
            trieNode* curr = trie;
            for(int i = 0; i < key.length(); i++)
            {
                if(curr->children.find(key[i]) == curr->children.end())
                {
                    curr->children[key[i]] = new trieNode();
                }
                curr = curr->children[key[i]];
                curr->sum += val;
            };
            se[key] = val;
        }
    };
    
    int sum(string prefix) {
        
        trieNode* curr = trie;
        for(int i = 0; i < prefix.length(); i++)
        {
            if(curr->children.find(prefix[i]) == curr->children.end())
            {
               return 0;
            }
            curr = curr->children[prefix[i]];
        }
        return curr->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */