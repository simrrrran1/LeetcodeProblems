class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,0);
        v[0]=1;
        for(int i=1;i<n;i++){
            v[i]=v[i-1]*nums[i-1];
        }
        int x=1;
        for(int i=n-1;i>=0;i--){
            v[i]=v[i]*x;
            x*=nums[i];
        }
        return v;
    }
};