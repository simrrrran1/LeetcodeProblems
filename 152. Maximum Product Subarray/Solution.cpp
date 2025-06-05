class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minPro = 1;
        int maxPro = 1;
        int ans = *max_element(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                minPro = 1;
                maxPro = 1;
                continue;
            }
            int temp = minPro;
            minPro = min(min(minPro * nums[i], maxPro * nums[i]), nums[i]);
            maxPro = max(max(maxPro * nums[i], temp * nums[i]), nums[i]);
            ans = max(ans, maxPro);
        }
        return ans;
    }
};