class LRUCache {
public:
    
    typedef struct{
        int key;
        int value;
        // int count;
    }node;
    
    typedef list<node> lfuLis;
    lfuLis lfuList;
    typedef map<int, lfuLis::iterator> lfuM;
    lfuM lfuMap;
    
    int size, curr;
    LRUCache(int capacity) {
        size = capacity;
        curr = 0;
    };
    
    int get(int key) {
        auto itr = lfuMap.find(key);
        if(itr != lfuMap.end())
        {
            auto nItr = promote(itr->second);
            lfuMap[key] = nItr;
            // nItr->count = nItr->count + 1;
            return nItr->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto itr = lfuMap.find(key);
        if(itr != lfuMap.end())
        {
            auto nItr = promote(itr->second);
            lfuMap[key] = nItr;
            nItr->value = value;
            // nItr->count = nItr->count + 1;
        }
        else
        {
            if(curr >= size)
            {
                node tmp = lfuList.front();
                lfuList.pop_front();
                lfuMap.erase(tmp.key);
                curr--;
            }
            node newNode;
            newNode.key = key;
            newNode.value = value;
            // newNode.count = 1;
            auto itr = lfuList.insert(lfuList.end(), newNode);
            lfuMap[key] = itr;
            curr++;
        }
    }
    
    lfuLis::iterator promote(lfuLis::iterator itr)
    {
        auto nItr = lfuList.insert(lfuList.end(), *itr);
        lfuList.erase(itr);
        return nItr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */