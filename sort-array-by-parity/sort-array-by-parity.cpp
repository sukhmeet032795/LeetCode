class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int len = A.size();
        int start = 0, end = len-1;
        
        while(start < end)
        {
            if(A[end] % 2 != 0)
                end--;
            else if(A[start] % 2 == 0)
                start++;
            else
            {
                swap(A[start], A[end]);
                start++;
                end--;
            }
        }
        
        return A;
    }
};