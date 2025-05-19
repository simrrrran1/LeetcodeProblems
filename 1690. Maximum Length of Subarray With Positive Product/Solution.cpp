class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0, pos = 0, neg = 0;
        
        for(int i: nums){
            if(i > 0){
                pos = 1 + pos;
                if(neg)
                    neg = 1 + neg;
                else 
                    neg = 0;
            }else if(i == 0){
                pos = 0;
                neg = 0;
            }else{
                int temp = pos;
                if(neg)
                    pos = 1 + neg;
                else
                    pos = 0;
                neg = 1 + temp;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};