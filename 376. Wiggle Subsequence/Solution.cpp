class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int last = nums[1] - nums[0];
        int len = last == 0 ? 1 : 2;

        for(int i=2; i<nums.size(); i++){
            int curr = (nums[i] - nums[i-1]);
            if(curr > 0 && last <= 0 || curr < 0 && last >= 0){
                len++;
                last = curr;
            }
        }
        return len;
    }
};

// [1, 7, 4, 9, 2, 5]
// [6, -3, 5, -7, 3]