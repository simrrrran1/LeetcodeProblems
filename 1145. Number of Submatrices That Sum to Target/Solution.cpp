class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> subSum(row, vector<int>(col, 0));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int left = i>0 ? subSum[i-1][j] : 0;
                int top = j>0 ? subSum[i][j-1] : 0;
                int topLeft = min(i,j) > 0 ? subSum[i-1][j-1] : 0;

                subSum[i][j] = matrix[i][j] + top + left - topLeft;
            }
        }

        int res = 0;

        for(int r1=0; r1<row; r1++){
            for(int r2=r1; r2<row; r2++){
                unordered_map<int,int> mp;
                mp[0] = 1;
                for(int c=0; c<col; c++){
                    int curr = subSum[r2][c] - (r1 > 0 ? subSum[r1-1][c] : 0);
                    int diff = curr - target;
                    res += mp[diff];
                    mp[curr]++;
                }
            }

        }



        return res;

    }
};