class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0;
        int sumCost = 0;
        int n = gas.size();
        for(int i=0; i<n; i++){
            sumGas += gas[i];
            sumCost += cost[i];
        }
        if(sumCost > sumGas) return -1;

        int ans = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += (gas[i] - cost[i]);
            if(sum < 0){
                sum = 0;
                ans = i+1;
            }
        }
        return ans;




    }
};


//gas =   [1,   2,  3,  4, 5] 
//cost =  [3,   4,  5,  1, 2]
//total = [-2, -2, -2,  3, 3]