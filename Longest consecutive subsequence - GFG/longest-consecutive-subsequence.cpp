//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int N)
    {
        unordered_map<int, int> seq;
        int len = N, Max = 0;
        for (int itr = 0; itr < len; ++itr) {
            int num = nums[itr];
            if (!seq.count(num)) {
                int count = 1 + (seq.count(num - 1) ? seq.at(num - 1) : 0) + (seq.count(num + 1) ? seq.at(num + 1) : 0);
                Max = max(Max, count);
                seq[num] = count;
                if (seq.count(num - 1)) seq[num - seq.at(num - 1)] = count;
                if (seq.count(num + 1)) seq[num + seq.at(num + 1)] = count;
            }
        };
    
        return Max;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends