//     bool isPalindrome(string &str)
//     {
//         int start = 0, len = str.length(), end = len - 1;
//         while(start < end)
//         {
//             if(str[start] != str[end])
//                 return false;
//             start++;
//             end--;
//         };
//         return true;
//     };
    
//     bool checkPalindromeFormation(string a, string b) {
        
//         int len = a.length();
//         if(len == 1)
//             return true;
    
//         string f1 = "", f2 = a, s1 = "", s2 = b;
//         for(int i = 0; i < len; i++)
//         {
//             string tmp1 = (f1 + s2), tmp2 = (s1 + f2);
//             if(isPalindrome(tmp1) || isPalindrome(tmp2))
//                 return true;
            
//             if((i+1) != len)
//             {
//                 f1 += f2[0];
//                 f2.erase(f2.begin());
                
//                 s1 += s2[0];
//                 s2.erase(s2.begin());
//             }
//         };
        
//         return false;
//     };

class Solution {
public:
    int n;
    bool isPalindrome(string s,int i,int j) {
        while (i < j && s[i] == s[j])
            i++, j--;
        return i >= j;
    }
    bool checkPalindrome(string a, string b){
        int i=0,j=a.size()-1;
        while(i<j && a[i]==b[j])
            i++,j--;
        return isPalindrome(a,i,j) || isPalindrome(b,i,j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return checkPalindrome(a,b) ||checkPalindrome(b,a);
    }
};