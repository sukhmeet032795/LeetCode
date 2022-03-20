class LRUCache {
private:
    struct node {
        int key;
        int value;
        node(int k, int v) : key(k), value(v) {};
    };
    
    typedef list<node> lruListType;
    lruListType lruList;
    unordered_map<int, lruListType::iterator> m;
    
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    };
    
    int get(int key) {
        auto itr = m.find(key);
        if (itr != m.end()) {
            lruListType::iterator itr1 = lruList.insert(lruList.end(), *(itr->second));
            lruList.erase(itr->second);
            m[key] = itr1;
            return itr1->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto itr = m.find(key);
        if (itr == m.end()) {
            if (m.size() >= cap) {
                node n1 = lruList.front();
                lruList.pop_front();
                m.erase(n1.key);
            };
            lruListType::iterator itr = lruList.insert(lruList.end(), node(key, value));
            m[key] = itr;
        } else {
            lruListType::iterator itr1 = lruList.insert(lruList.end(), *(itr->second));
            lruList.erase(itr->second);
            m[key] = itr1;
            itr1->value = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */