class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums)sum+=i;
        int ans= (n)*(n+1)/2;
        return (ans-sum);
    }
};