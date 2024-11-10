class Solution {
public:
    //[rob1, rob2, i, i+1, .......]
    int rob(vector<int>& nums) {
       int n=nums.size();
       int rob1=nums[0];
       if(n==1)return rob1;
       int rob2=max(nums[0],nums[1]);
       if(n==2)return rob2;
       for(int i=2;i<n;i++){
            int curr=max(rob1+nums[i],rob2);
            rob1=rob2;
            rob2=curr;
       }
       return rob2; 
       
    }
};