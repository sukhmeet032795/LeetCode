//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        
        int end = 0, maxEnd = 0, itr = 0, len = n, steps = 0;
        for ( ; itr < (len - 1); ) {
            ++steps;
            for ( ; itr <= end; ++itr ) {
                maxEnd = max(maxEnd, itr + arr[itr]);
                if (maxEnd >= (len - 1)) return steps;
            }

            if (end == maxEnd) return -1;
            end = maxEnd;
        };
        
        return steps;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends