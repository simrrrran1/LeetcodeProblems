class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1)return s;
        int row=0;
        bool dir=true;
        string ans="";
        vector<string> v(numRows,"");
        for(int i=0;i<n;i++){
            v[row].push_back(s[i]);
            if(row==numRows-1)dir=false;
            else if(row==0)dir=true;
            if(dir==true)row++;
            else row--;
        }
        for(int i=0;i<numRows;i++)ans+=v[i];
        return ans;
    }
};