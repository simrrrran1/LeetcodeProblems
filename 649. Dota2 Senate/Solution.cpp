class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;
        int n = senate.size();

        for(int i=0; i<n; i++){
            if(senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }

        while(!radiant.empty() && !dire.empty()){
            int rFront = radiant.front();
            radiant.pop();
            int dFront = dire.front();
            dire.pop();

            if(rFront < dFront)
                radiant.push(rFront + n);
            else
                dire.push(dFront + n);
        }

        return !radiant.empty() ? "Radiant" : "Dire";
    }
};