class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,v=0;
        for(int i:nums){
            if(cnt==0){
                v=i;
            }
            if(i==v){
                cnt++;
            }else {
                cnt--;
            }
        }
        return v;
    }
};