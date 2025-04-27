class Solution {
public:
    int count(vector<vector<int>>& matrix, int mid, int n){
        int row = 0, col = n-1, ans = 0;
        while(row < n && col >= 0){
            if(matrix[row][col] <= mid){
                ans += (col+1);
                row++;
            }else{
                col--;
            }
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(k == 1) return matrix[0][0];
        
        int low = matrix[0][0], high = matrix[n-1][n-1];

        while(low < high){
            int mid = low + (high-low)/2;
            int c = count(matrix, mid, n);
            if(c < k) low = mid + 1;
            else high = mid;
        }
        return low;
        
    }
};