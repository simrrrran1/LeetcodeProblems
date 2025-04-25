#include<map>
#include<unordered_map>
#include<vector>

class disjointS{
    vector <int> parent, size;
    public:
    disjointS(int n){
        size.resize(n+1,0);
        parent.resize(n+1);
        for (int i =0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int i){
        if (parent[i]==i) return i;
        return parent[i]=findUParent(parent[i]);
    }

    void unionBySize(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if (size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else if (size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjointS ds(n);
        unordered_map<string,int> mapMail;
        for (int i =0;i<n;i++){
            for (int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if (mapMail.find(mail)==mapMail.end()){
                    mapMail[mail]=i;
                }
                else{
                    ds.unionBySize(i,mapMail[mail]);
                }
            }
        }
        vector<vector<string>>mappedMail(n);
        for(auto it:mapMail){
                string mail=it.first;
                int node=ds.findUParent(it.second);
                mappedMail[node].push_back(mail);
        }
        

        vector<vector<string>> ans;

        
        for(int i=0;i<n;i++){
            if (mappedMail[i].size()==0) continue;
            sort(mappedMail[i].begin(),mappedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto mail:mappedMail[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};