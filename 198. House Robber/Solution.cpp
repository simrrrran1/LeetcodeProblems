class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            ans = max(rob2, nums[i] + rob1);
            rob1 = rob2;
            rob2 = ans;
        }
        return rob2;
    }
};