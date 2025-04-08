class Solution {
public:
    void helper(vector<vector<int>>& rooms, int start, vector<bool>& vis){
        if(vis[start]) return;
        vis[start] = true;

        for(auto& i: rooms[start]){
            if(!vis[i]){
                helper(rooms, i, vis);
            }
        }

        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);

        helper(rooms, 0, vis);
        for(int i=0; i<n; i++){
            if(vis[i] == false) return false;
        }

        return true;


    }
};