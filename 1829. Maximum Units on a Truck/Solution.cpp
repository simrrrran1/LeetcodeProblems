class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });

        for(int i=0; i<n; i++)
        cout<< boxTypes[i][0]<< " " << boxTypes[i][1] << endl;

        int ans = 0;
        for(int i=0; i<n; i++){
            int count = min(truckSize, boxTypes[i][0]);  // Load as many boxes as possible
            ans += count * boxTypes[i][1];               // Add units
            truckSize -= count;                  // Reduce remaining truck capacity

            if (truckSize == 0) break;
        }
        return ans;
    }
};

// [[5,10],[2,5],[4,7],[3,9]]
// [[2,5], [4,7], [3,9], [5,10]]