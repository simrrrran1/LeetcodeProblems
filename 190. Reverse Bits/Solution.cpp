class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t revN = 0;
        for(int i=0; i<32; i++){
            revN = revN << 1;
            int bit = n & 1;
            revN = revN | bit;
            n = n >> 1;
        }
        return revN;
    }
};