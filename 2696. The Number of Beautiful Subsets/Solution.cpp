class Solution {
public:
    unordered_map<int,int> cache;
    int helper(int n, unordered_map<int,int>& g, int k){
    if(g.find(n) == g.end()) return 1;
    if(cache.find(n) != cache.end()) return cache[n];

    int skip = helper(n + k, g, k);
    int count = g[n];
    int include = (pow(2, count) - 1) * helper(n + 2 * k, g, k);
    cache[n] = skip + include;
    return cache[n];
}

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> freq;

        for(int i: nums){
            freq[i]++;
        }

        unordered_set<int> vis;
        vector<unordered_map<int,int>> grpList;

        for(auto& i: freq){
            int num = i.first;
            int occ = i.second;
            if(vis.find(num) != vis.end()) continue;

            unordered_map<int,int> mp;

            while(freq.count(num - k)) num -= k;

            while(freq.count(num)){
                mp[num] = freq[num];
                vis.insert(num);
                num += k;
            }
            grpList.push_back(mp);
        }

        int ans = 1;

        for(auto& g: grpList){
            int mini = INT_MAX;
            for(auto& i:g){
                mini = min(mini, i.first);
            }
            ans *= helper(mini, g, k);
        }
        return ans-1;
    }
};