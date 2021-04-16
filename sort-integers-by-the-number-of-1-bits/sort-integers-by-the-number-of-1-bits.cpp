class Solution {
public:
    struct node{
        int ones;
        int num;
        node(int o, int n) : ones(o), num(n) {};
    };
    
    int getSetBits(int n)
    {
        int len = 0;
        while(n != 0)
        {
            if(n & 1){
                len++;
            }
            n = n >> 1;
        }
        
        return len;
    };
    
    struct customSort{
        bool operator()(const node &n1, const node &n2)
        {
            if(n1.ones == n2.ones)
                return n1.num < n2.num;
            return n1.ones < n2.ones;
        }
    };
    
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<node> tmp;
        int len = arr.size();
        for(int i = 0; i < len; i++)
        {
            int bits = getSetBits(arr[i]);
            tmp.push_back(node(bits, arr[i]));
        }
        
        sort(tmp.begin(), tmp.end(), customSort());
        
        arr.clear();
        for(auto itr : tmp)
            arr.push_back(itr.num);
        
        return arr;
    }
};