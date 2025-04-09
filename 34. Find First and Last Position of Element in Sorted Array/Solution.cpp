class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2, -1);
        int n = nums.size();
        int left = 0, right = n-1;

        while(left <= right){
            int mid = left + ((right-left)/2);

            if(nums[mid] < target) left = mid+1;
            else if(nums[mid] > target) right = mid-1;
            else{
                int x = mid-1;
                while(x>=0 && nums[mid] == nums[x]){
                    x--;
                }
                v[0] = x+1;
                int y = mid+1;
                while(y<n && nums[mid] == nums[y]){
                    y++;
                }
                v[1] = y-1;
                break;
            }
        }
        return v;
    }
};