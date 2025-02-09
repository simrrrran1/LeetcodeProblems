class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxAltitude = 0;
        int curr = 0;
        for(int i=0; i<n; i++){
            curr += gain[i];
            maxAltitude = max(maxAltitude, curr);
        }
        return maxAltitude;
    }
};