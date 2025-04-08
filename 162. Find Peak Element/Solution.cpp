class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + ((right-left)/2);

            if(mid > 0 && nums[mid-1] > nums[mid]) right = mid - 1;

            else if(mid < nums.size()-1 && nums[mid+1] > nums[mid]) left = mid + 1;

            else return mid;
        }
        return -1;
    }
};