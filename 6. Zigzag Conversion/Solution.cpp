class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows);
        int i = 0;
        int row = 0, dir = 1;
        while(i<s.size()){
            v[row].push_back(s[i]);
            if(row == numRows-1) dir = -1;
            else if(row == 0) dir = 1;
            if(dir == 1) row++;
            else row--;
            i++;
        }
        string ans = "";
        for(int i=0; i<numRows; i++){
            ans += v[i];
        }
        return ans;
    }
};