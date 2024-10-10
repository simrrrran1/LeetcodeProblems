class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        for(int i=0;i<32;i++){
            uint32_t rem=(n>>i)&1;
            ans|=(rem<<(31-i));
        }
        return ans;
    }
};