class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;

        for(int i: nums){
            int x = i%value;
            if(x < 0) x += value;
            mp[x]++;
        }
        int ans = 0;
        while(true){
            if(mp[ans] == 0)return ans;
            int cnt = mp[ans];
            int k = 0;
            while(cnt--){
                mp[ans + (k * value)]++;
                k++;
            }
            ans++;
        }
        return -1;
    }
};