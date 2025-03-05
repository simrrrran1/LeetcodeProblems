class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> prefixMax(n,0);
        vector<int> suffixMax(n,0);

        prefixMax[0] = nums[0];

        for(int i=1; i<n; i++){
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }

        suffixMax[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], nums[i]);
        }

        for(int i=1; i<n-1; i++){
            long long diff = (prefixMax[i-1] - nums[i]) * 1LL * suffixMax[i+1];
            ans = max(ans, diff);
        }

        return ans;
    }
};