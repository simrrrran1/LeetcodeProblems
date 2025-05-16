class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> s;
        int prev_start_time = 0;

        for(int i=0; i<logs.size(); i++){
            int pos1 = logs[i].find(':');
            int pos2 = logs[i].find(':', pos1 + 1);
            int func_id = stoi(logs[i].substr(0, pos1));
            string msg = logs[i].substr(pos1 + 1, pos2 - pos1 - 1);
            int ts = stoi(logs[i].substr(pos2 + 1));

            if(msg == "start"){
                if(!s.empty()){
                    ans[s.top()] += (ts - prev_start_time);
                }
                s.push(func_id);
                prev_start_time = ts;
            }else{
                ans[s.top()] += (ts - prev_start_time + 1);
                s.pop();
                prev_start_time = ts + 1;
            }
        }


        return ans;
    }
};