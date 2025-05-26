class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        // for(int i=n-1; i>=0; i--){
        //     for(int j=1; j<=i; j++){
        //         nums[j-1] += nums[j];
        //         nums[j-1] = nums[j-1] % 10;
        //         cout<< nums[j-1] << " ";
        //     }
        //     cout<< endl;
        // }

        while(nums.size() > 1){

            for(int i=0; i<nums.size()-1; i++){
                nums[i] = (nums[i]+nums[i+1]) % 10;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};