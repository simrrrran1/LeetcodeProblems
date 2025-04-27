class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0;
        int pro = 1;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            pro *= nums[right];
            while(left<=right && pro >= k){
                pro /= nums[left];
                left++;
            }
            ans += (right - left + 1);
            right++;
        }
        return ans;
    }

    // nums = [10,5,2,6]
    // k = 100
    // [10], [5], [2], [6], [10, 5], [5,2], [2,6], [5, 2, 6]
    // left = 0, right = 0
    // pro = 1
    // pro
    // 10, 50, 100
    // 10, 60, 
    // right = 2
    // left = 1
    // totalCount = 2
};