class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> s;
        for(int i=0; i<edges.size(); i++){
            if(s.find(edges[i][0]) != s.end()){
                return edges[i][0];
            }
            if(s.find(edges[i][1]) != s.end()){
                return edges[i][1];
            }
            s.insert(edges[i][0]);
            s.insert(edges[i][1]);
        }
        return 0;
    }
};