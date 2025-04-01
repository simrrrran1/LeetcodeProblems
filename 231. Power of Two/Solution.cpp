class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int x = pow(2,30);
        // return n > 0 && ((x % n) == 0);

        return n > 0 && ( (n & (n-1))  == 0 );
        // if(n<1) return false;
        // int hammingWeight = 0;
        // while(n){
        //     hammingWeight += (n&1);
        //     n /= 2;
        // }
        // return hammingWeight == 1;
    }
};