class Solution {
public:
    void helper(vector<vector<int>>& image, int row, int col, int color, int source){
        if(row<0 || col<0 || row>=image.size() || col>=image[0].size() || image[row][col]!=source)return;
        image[row][col]=color;
        helper(image,row+1,col,color,source);
        helper(image,row-1,col,color,source);
        helper(image,row,col-1,color,source);
        helper(image,row,col+1,color,source);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        int source=image[sr][sc];
        int row=image.size();
        int col=image[0].size();
        helper(image,sr,sc,color,source);
        return image;
        
    }
};