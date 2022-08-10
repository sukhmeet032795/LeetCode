// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start = 0, end = n;
        while(start < end) {
            int mid = ((end - start) >> 1) + start;
            
            if (isBadVersion(mid) == false) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        };
        return start;
    }
};