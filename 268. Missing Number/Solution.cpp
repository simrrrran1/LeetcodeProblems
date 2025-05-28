class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i: nums) sum += i;
        int sum1 = n*(n+1)/2;
        return abs(sum1 - sum);
    }
};