class Solution {
public:
    int helper(int diff, vector<int>& nums){
        int l = 0;
        int ans = 0;
        for(int r = 0; r < nums.size(); r++){
            while((nums[r] - nums[l]) > diff) l++;
            ans += (r - l);
        }
        return ans;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = *max_element(nums.begin(), nums.end());

        while(left < right){
            int mid = left + (right-left)/2;
            int pairs = helper(mid, nums);
            if(pairs >= k){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return right;
    }
};