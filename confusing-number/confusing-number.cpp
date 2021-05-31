class Solution {
public:
    bool confusingNumber(int n) {
        
        unordered_map<int, int> m = {{0, 0}, {1,1}, {6,9}, {8,8}, {9,6}};
        
        int num = 0, multiply = 10, num1 = n;
        while(n != 0)
        {
            int tmp = n % 10;
            n = n /10;
            
            if(m.find(tmp) == m.end())
                return false;
            
            num = num*multiply + m[tmp];
        }
        // cout<<num<<" "<<num1<<endl;
        if(num == num1)
            return false;
        
        return true;
    }
};