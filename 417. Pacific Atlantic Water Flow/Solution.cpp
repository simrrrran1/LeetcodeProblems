class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, int n, int m, vector<vector<int>>&ans, int prevHeight){
        if(row<0 || col<0 || row>=n || col>=m || ans[row][col]==1 || heights[row][col]<prevHeight)return;
        ans[row][col]=1;
        dfs(heights,row+1,col,n,m,ans,heights[row][col]);
        dfs(heights,row-1,col,n,m,ans,heights[row][col]);
        dfs(heights,row,col-1,n,m,ans,heights[row][col]);
        dfs(heights,row,col+1,n,m,ans,heights[row][col]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();int m=heights[0].size();
        vector<vector<int>>v;
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dfs(heights,0,i,n,m,pacific,heights[0][i]);
            dfs(heights,n-1,i,n,m,atlantic,heights[n-1][i]);
        }

        for(int i=0;i<n;i++){
            dfs(heights,i,0,n,m,pacific,heights[i][0]);
            dfs(heights,i,m-1,n,m,atlantic,heights[i][m-1]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]&&atlantic[i][j])v.push_back({i,j});
            }
        }
        return v;

    }
};