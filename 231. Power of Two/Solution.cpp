class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        int hammingWeight = 0;
        while(n){
            hammingWeight += (n&1);
            n /= 2;
        }
        return hammingWeight == 1;
    }
};