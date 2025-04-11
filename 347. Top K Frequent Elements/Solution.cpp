class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == 1 && nums.size() == 1) return {nums[0]};

        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> ans(nums.size()+1);

        for(auto i:mp){
            int x = i.second;
            ans[x].push_back(i.first);
        }

        vector<int> v;
        for(int i=ans.size()-1; i>=0; i--){
            while(ans[i].size()>0 && k>0){
                v.push_back(ans[i].back());
                ans[i].pop_back();
                k--;
            }
        }

        return v;


        //vector<int> v;


        
        // priority_queue<pair<int,int>> pq;
        // for(auto i:mp){
        //     pq.push({i.second, i.first});
        // }

        // vector<int> v;
        // for(int i=0; i<k; i++){
        //     v.push_back(pq.top().second);
        //     pq.pop();
        // }

        //return v;
    }
};