class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs;
        vector<string> digit_logs;
        vector<string> ans;

        for(int i=0; i<logs.size(); i++){
            int idx = logs[i].find(" ") + 1;
            if(logs[i].at(idx) >= '0' && logs[i].at(idx) <= '9'){
                digit_logs.push_back(logs[i]);
            }else{
                letter_logs.push_back(logs[i]);
            }
        }

        sort(letter_logs.begin(), letter_logs.end(), [](const string&a , const string&b){
            int space1 = a.find(" ") + 1;
            int space2 = b.find(" ") + 1;

            string contentA = a.substr(space1);
            string contentB = b.substr(space2);

            if(contentA == contentB){
                return a < b;
            }
            return contentA < contentB;
        });

        for(auto i: letter_logs){
            ans.push_back(i);
        }
        for(int i=0; i<digit_logs.size(); i++){
            ans.push_back(digit_logs[i]);
        }
        return ans;






        return ans;
    }
};