class Solution {
public:
    
//     struct node{
//         char key;
//         int count;
//         node(char k, int c) : key(k), count(c) {};
//     };
    
//     string removeDuplicates(string s1, int k) {
        
//         int len = s1.length();
//         stack<node> s;
        
//         int end = 0, count = 0;
//         while(end < len)
//         {
//             if(s.empty())
//             {
//                 s.push(node(s1[end], 1));
//                 end++;
//             }
//             else
//             {
//                 if(s.top().key != s1[end])
//                 {
//                     s.push(node(s1[end], 1));
//                 }
//                 else if(s.top().key == s1[end])
//                 {
//                     s.top().count = (s.top().count + 1);
//                 }
//                 end++;
//                 if(s.top().count >= k)
//                 {
//                     s.pop();
//                 }
//             }
//         };
        
//         string out = "";
        
//         while(!s.empty())
//         {
//             node tmp = s.top();
//             s.pop();
            
//             if(tmp.count == k)
//                   continue;
            
//             for(int i = 0; i < tmp.count; i++)
//                 out = tmp.key + out;
//         }
        
//         return out;
//     }
    
    string removeDuplicates(string s, int k) {
        auto j = 0;
        stack<int> counts;
        for (auto i = 0; i < s.size(); ++i, ++j) {
            s[j] = s[i];
            if (j == 0 || s[j] != s[j - 1]) {
                counts.push(1);
            } else if (++counts.top() == k) {
                counts.pop();
                j -= k;
            }
        }
        return s.substr(0, j);
    }
};