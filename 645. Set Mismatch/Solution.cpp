class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long sum = 0;
        long sqSum = 0;
        for(int i=1; i<=nums.size(); i++){
            sum += (nums[i-1] - i);
            sqSum += (nums[i-1] * nums[i-1]) - (i * i);
        }
        
        int missing = (sqSum - (sum * sum)) / (2 * sum);
        int duplicate = missing + sum;

        return {duplicate, missing};  
        
    }
};