class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int up = 0, down = row - 1, left = 0, right = col - 1;
        int dir = 0;
        vector<int> v;

        while(up <= down && left <= right){
            switch(dir){
                case 0:
                    for(int i=left; i<=right; i++){
                        v.push_back(matrix[up][i]);
                    }
                    up++;
                    dir++;
                    break;
                case 1:
                    for(int i=up; i<=down; i++){
                        v.push_back(matrix[i][right]);
                    }
                    right--;
                    dir++;
                    break;
                case 2:
                    for(int i=right; i>=left; i--){
                        v.push_back(matrix[down][i]);
                    }
                    down--;
                    dir++;
                    break;
                case 3:
                    for(int i=down; i>=up; i--){
                        v.push_back(matrix[i][left]);
                    }
                    left++;
                    dir++;
                    break;

            }
            dir %= 4;

        }
        return v;
    }

};