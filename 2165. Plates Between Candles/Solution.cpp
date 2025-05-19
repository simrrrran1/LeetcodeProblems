class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
      int n = s.size(),cnt = 0;
      vector<int> prec(n,0),cp,ans;
      for(int i = 0;i<n;i++)
      {
         if(s[i]=='*') cnt++;
         if(s[i]=='|') cp.push_back(i);
         prec[i] = cnt;
      }
      for(int i = 0;i<q.size();i++)
      {
          int l = lower_bound(cp.begin(),cp.end(),q[i][0])-cp.begin();
          int r = upper_bound(cp.begin(),cp.end(),q[i][1])-cp.begin();
          if(l<0 || l>=cp.size() || r<=0 || r>cp.size() || prec[cp[r-1]]-prec[cp[l]]<0) ans.push_back(0);
          else ans.push_back(prec[cp[r-1]]-prec[cp[l]]);
      }
      return ans;  
    }
};