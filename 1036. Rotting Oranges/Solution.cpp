class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int minutes = 0;

        int row = grid.size();
        int col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }

        vector<vector<int>> coordinates = {{0,-1}, {0,1}, {1,0}, {-1,0}};

        while(!q.empty() && fresh>0){
            minutes += 1;
            int k = q.size();

            for(int i=0; i<k; i++){
                pair<int,int> p = q.front();
                q.pop();
                for(int j=0; j<4; j++){
                    int dx = p.first + coordinates[j][0];
                    int dy = p.second + coordinates[j][1];

                    if(dx>=0 && dy>=0 && dx<row && dy<col && grid[dx][dy]==1){
                        grid[dx][dy] = 2;
                        fresh -= 1;
                        if(fresh == 0) return minutes;
                        q.push({dx, dy});
                    }
                }
            }

        }

        if(fresh > 0) return -1;
        else return minutes;
    }
};