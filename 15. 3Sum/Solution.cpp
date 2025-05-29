class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<nums.size()-2; i++){
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            } 
            int left = i+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[++left]);
                    while(left < right && nums[right] == nums[--right]);
                    
                }else if(sum < 0){
                    left++;
                }else {
                    right--;
                }
            }

        }



        return ans;
    }
};