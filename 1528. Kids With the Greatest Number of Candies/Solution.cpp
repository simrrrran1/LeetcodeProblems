class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxi = *max_element(candies.begin(), candies.end());
        
        vector<bool> v(n, false);
        for(int i=0; i<n; i++){
            if(candies[i] + extraCandies >= maxi) v[i] = true;
        }
        return v;
    }
};