class Solution {
private:
    std::array<int, 38> arrNums;
    void helper() {
        arrNums[0] = 0;
        arrNums[1] = 1;
        arrNums[2] = 1;
        for (int i = 3; i <= 37; ++i)
            arrNums[i] = arrNums[i - 1] + arrNums[i - 2] + arrNums[i - 3];        
    }

public:
    int tribonacci(int n) {
        helper();
        return arrNums[n];
    }
};