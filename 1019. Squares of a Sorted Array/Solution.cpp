class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        int left = 0, right = nums.size()-1, k = nums.size()-1;
        while(left <= right){
            int l = nums[left] * nums[left];
            int r = nums[right] * nums[right];
            if(l > r){
                v[k] = l;
                left++;
            }else{
                v[k] = r;
                right--;
            }
            k--;
        }

        return v;
    }
};