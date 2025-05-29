class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        if(n < 4) return {};

        for(int i=0; i<n-3; i++){
            if(i > 0 && nums[i-1] == nums[i]){
                    continue;
            }
            for(int j=i+1; j<nums.size()-2; j++){
                if(j > i+1 && nums[j-1] == nums[j]){
                    continue;
                } 
                int left = j+1, right = nums.size()-1;
                while(left < right){
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[++left]);
                        while(left < right && nums[right] == nums[--right]);
                    
                    }else if(sum < target){
                        left++;
                    }else {
                        right--;
                    }
                }

            }

        }
        return ans;

    }
};