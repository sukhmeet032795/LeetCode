class FileSystem {
public:
    
    struct trieNode{
        map<string, trieNode*> children;
        map<string, string> fileContent;
    };
    
    queue<string> getPath(string path) {
        queue<string> out;
        path.erase(path.begin());
        stringstream ss(path);
        string tmp;
        while(getline(ss, tmp, '/')) {
            out.push(tmp);
        }
        return out;
    }
    
    trieNode* trie = NULL;
    FileSystem() {
        trie = new trieNode();
    }
    
    vector<string> ls(string path) {
        queue<string> paths = getPath(path);
        vector<string> out;
        trieNode* tmp = trie;
        while(!paths.empty()) {
            string val = paths.front();
            paths.pop();
            if(tmp->children.find(val) == tmp->children.end())
                return {val};
            tmp = tmp->children[val];
        };
        
        for(auto itr : tmp->children) {
            out.push_back(itr.first);
        }
        
        for(auto itr : tmp->fileContent) {
            out.push_back(itr.first);
        }
        sort(out.begin(), out.end());
        return out;
    }
    
    void mkdir(string path) {
        queue<string> paths = getPath(path);
        trieNode* tmp = trie;
        while(!paths.empty()) {
            string val = paths.front();
            paths.pop();
            if(tmp->children.find(val) == tmp->children.end()) {
                tmp->children[val] = new trieNode();
            }
            tmp = tmp->children[val];
        };
    }
    
    void addContentToFile(string filePath, string content) {
        queue<string> paths = getPath(filePath);
        trieNode* tmp = trie;
        while(paths.size() != 1) {
            string val = paths.front();
            paths.pop();
            if(tmp->children.find(val) == tmp->children.end()) {
                tmp->children[val] = new trieNode();
            }
            tmp = tmp->children[val];
        };
        string val = paths.front();
        tmp->fileContent[val] += content;
    }
    
    string readContentFromFile(string filePath) {
        queue<string> paths = getPath(filePath);
        trieNode* tmp = trie;
        while(paths.size() != 1) {
            string val = paths.front();
            paths.pop();
            if(tmp->children.find(val) == tmp->children.end()) {
                tmp->children[val] = new trieNode();
            }
            tmp = tmp->children[val];
        };
        string val = paths.front();
        return tmp->fileContent[val];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */