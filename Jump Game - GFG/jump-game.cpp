//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        
        int end = 0, maxEnd = 0, itr = 0, len = N;
        for ( ; itr < (len - 1); ) {
            
            for ( ; itr <= end; ++itr ) {
                maxEnd = max(maxEnd, itr + A[itr]);
                if (maxEnd >= (len - 1)) return true;
            }

            if (end == maxEnd) return false;
            end = maxEnd;
        };
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends