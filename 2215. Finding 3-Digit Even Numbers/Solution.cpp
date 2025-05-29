class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> v;
        unordered_map<int, int> mp;
        for(int i: digits){
            mp[i]++;
        }
        vector<int> ans;

        for(int i=100; i<1000; i++){
            int first = i % 10;
            int second = (i / 10) % 10;
            int third = (i / 100) % 10;

            unordered_map<int,int> mp1;
            mp1[first] += 1;
            mp1[second] += 1;
            mp1[third] += 1;

            if(mp1[first] <= mp[first] && mp1[second] <= mp[second] && mp1[third] <= mp[third] && (i % 2 == 0)){
                ans.push_back(i);
            }

        }

        return ans;
    }
};