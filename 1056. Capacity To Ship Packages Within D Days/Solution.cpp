class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long right = 0;
        long left = weights[0];
        for(int i: weights){
            if(left < i)
                left = i;
            right += i;
        }

        int capacity = right;

        while(left <= right){
            long minCapacity = left + (right - left) / 2;

            int daysTaken = 1, currCapacity = 0;
            for(int i: weights){
                if(currCapacity + i > minCapacity){
                    daysTaken++;
                    currCapacity = 0;
                }
                currCapacity += i;
            }

            if(daysTaken <= days){
                if(capacity >= minCapacity){
                    capacity = minCapacity;
                }
                right = minCapacity - 1;
            }else{
                left = minCapacity + 1;
            }

        }

        return capacity;
    }
};