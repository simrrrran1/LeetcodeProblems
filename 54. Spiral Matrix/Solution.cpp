class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int up=0,down=row-1,left=0,right=col-1;
        int dir=0;
        vector<int>v;
        while(up<=down && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++)v.push_back(matrix[up][i]);
                up++;
            }else if(dir==1){
                for(int i=up;i<=down;i++)v.push_back(matrix[i][right]);
                right--;
            }else if(dir==2){
                for(int i=right;i>=left;i--)v.push_back(matrix[down][i]);
                down--;
            }else{
                for(int i=down;i>=up;i--)v.push_back(matrix[i][left]);
                left++;
            }
            dir=(dir+1)%4;
        }
        return v;
    }
};