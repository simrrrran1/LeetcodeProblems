class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(char c: s){
            mp[c]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto i: mp){
            pq.push({i.second, i.first});
        }

        pair<int, char> prev = {0, '#'};
        string res = "";

        while(!pq.empty() || (prev.first > 0)){
            if(prev.first > 0 && pq.empty()) return ""; // No valid reorg

            pair<int, char> p = pq.top(); pq.pop(); // FIXED: pop the top
            res += p.second;
            p.first--;

            if(prev.first > 0) {
                pq.push(prev);
            }

            if(p.first > 0){
                prev = p;
            } else {
                prev = {0, '#'};
            }
        }
        return res;
    }
};