class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        int minutes=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty() && fresh>0){
            int k=q.size();
            minutes++;
            while(k--){
                int row=q.front().first, col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int x=row+dx[i],y=col+dy[i];
                    if(x>=0&&y>=0&&x<rows&&y<cols&&grid[x][y]==1){
                        grid[x][y]=2;
                        fresh--;
                        q.push({x,y});
                        if(fresh==0)return minutes;
                    }
                }
            }
        }
        if(fresh==0)return minutes;
        return -1;
    }
};