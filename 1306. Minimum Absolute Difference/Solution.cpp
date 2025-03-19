class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> v;
        sort(arr.begin(), arr.end());
        int minD = abs(arr[1] - arr[0]);

        for(int i=1; i<arr.size(); i++){
            int diff = abs(arr[i]-arr[i-1]);
            minD = min(minD, diff);
        }

        for(int i=1; i<arr.size(); i++){
            int diff = abs(arr[i] - arr[i-1]);
            if(diff == minD){
                v.push_back({arr[i-1], arr[i]});
            }
        }

        return v;
    }
};