class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> descOrder(n, 0);
        vector<int> ascOrder(n, 0);

        for(int i=1; i<n; i++){
            if(security[i-1] >= security[i]) descOrder[i] = 1 + descOrder[i-1];
            else descOrder[i] = 0;
        }

        for(int i=n-2; i>=0; i--){
            if(security[i+1] >= security[i]) ascOrder[i] = 1 + ascOrder[i+1];
            else ascOrder[i] = 0;
        }

        vector<int> ans;

        for(int i=time; i<n-time; i++){
            if(descOrder[i] >= time && ascOrder[i] >= time) ans.push_back(i); 
        }


        return ans;


    }
};