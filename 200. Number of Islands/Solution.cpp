class Solution {
public:
    void helper(vector<vector<char>>& grid,int i,int j,int n, int m){
        if(i<0||j<0||i>=n||j>=m||grid[i][j]!='1')return;
        grid[i][j]='2';
        helper(grid,i-1,j,n,m);
        helper(grid,i+1,j,n,m);
        helper(grid,i,j-1,n,m);
        helper(grid,i,j+1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    helper(grid,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};