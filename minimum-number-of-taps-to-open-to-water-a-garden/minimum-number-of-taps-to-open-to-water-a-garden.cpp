class Solution {
public:
    int minTaps(int n, vector<int>& a) {
        
        for(int i=0;i<a.size();i++){
            a[max(0,i-a[i])] = max(a[max(0,i-a[i])], i+a[i]);
        }
        
        int maxdis=0, jmps=0, cur=0;
        for(int i=0;i<a.size()-1;i++){
            cur=max(cur, a[i]);
            if(i==maxdis){
                if(cur == maxdis) return -1;
                jmps++;
                maxdis=cur;
            }
        }
        
        return jmps;
    }
};