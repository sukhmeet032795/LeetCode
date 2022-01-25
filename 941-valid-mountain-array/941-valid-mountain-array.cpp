class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int len = arr.size();
        if(len < 3)
            return false;
        
        if(arr[0] > arr[1])
            return false;
        
        bool check = false;
        for(int i = 1; i < (len - 1); i++) {
            if(arr[i]  > arr[i-1] && arr[i] > arr[i+1]) {
                if(check == true)
                    return false;
                check = true;
            }
            else if ((arr[i] <= arr[i-1] && arr[i] <= arr[i+1]) || 
                        (arr[i] >= arr[i-1] && arr[i] >= arr[i+1]))
                return false;
        }
        
        return check;
    }
};