class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLog;
        vector<string> digitLog;
        vector<string> ans;

        for(int i=0; i<logs.size(); i++){
            int idx = logs[i].find(" ") + 1;
            if(logs[i][idx] >= '0' && logs[i][idx] <= '9'){
                digitLog.push_back(logs[i]);
            }else{
                letterLog.push_back(logs[i]);
            }
        }

        sort(letterLog.begin(), letterLog.end(), [](string& a, string& b){
            int aIdx = a.find(" ") + 1;
            int bIdx = b.find(" ") + 1;

            string contentA = a.substr(aIdx);
            string contentB = b.substr(bIdx);

            if(contentA == contentB){
                return a < b;
            }
            return contentA < contentB;
        });

        for(int i=0; i<letterLog.size(); i++) ans.push_back(letterLog[i]);
        for(int i=0; i<digitLog.size(); i++) ans.push_back(digitLog[i]);

        return ans;
    }
};