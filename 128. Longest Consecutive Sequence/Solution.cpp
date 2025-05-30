class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0; i<n; i++) s.insert(nums[i]);
        int ans = 0;
        for(int i: s){
            int x = i;
            if(s.find(x-1) == s.end()){
                int curr = 1;
                while(s.find(x+1) != s.end()){
                    curr++;
                    x += 1;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};