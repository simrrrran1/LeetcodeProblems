class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return 0;
        int ans=0;
        int left=0,right=0;
        while(right<n-1){
            int maxIdx=0;
            for(int i=left;i<=right&&i<n;i++){
                maxIdx=max(maxIdx,i+nums[i]);
            }
            left=right+1;
            right=maxIdx;
            ans++;
        }
        return ans;

    }
};