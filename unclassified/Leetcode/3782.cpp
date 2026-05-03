class Solution {
public:
    int mirrorDistance(int n) {
        int reversed = 0, cpy = n;
        for (int i = 0; n > 0; i++) {
            int r = n % 10;
            reversed = (reversed * 10) + r;
            n/=10;
        }
        
        return abs(cpy - reversed);
    }
};