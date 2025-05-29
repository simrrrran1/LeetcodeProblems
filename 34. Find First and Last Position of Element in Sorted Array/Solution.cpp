class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2, -1);
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                int c1 = mid - 1;
                while(c1 >=0 && nums[c1] == nums[mid]){
                    c1--;
                }
                int c2 = mid + 1;
                while(c2 < n && nums[c2] == nums[mid]){
                    c2++;
                }
                v[0] = c1+1;
                v[1] = c2-1;
                break;
            }else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        } 
        return v;
    }
};