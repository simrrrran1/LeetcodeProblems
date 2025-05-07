class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        vector<double> ans;

        for(int i=0; i<k; i++){
            maxHeap.push(nums[i]);
        }

        for(int i=0; i<k/2; i++){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        

        for(int i=k; i<nums.size(); i++){
            double median;
            if(k % 2 == 0){
                median = ((1.0 * minHeap.top() + 1.0 * maxHeap.top()) / 2) ;
                ans.push_back(median);
            }else{
                median = 1.0 * maxHeap.top();
                ans.push_back(median);
            }

            int prev = nums[i-k], curr = nums[i], balance = 0;

            if(prev <= maxHeap.top()){
                balance--;
                if(maxHeap.top() == prev){
                    maxHeap.pop();
                }else{
                    mp[prev]++;
                }
            }else{
                balance++;
                if(prev == minHeap.top()){
                    minHeap.pop();
                }else{
                    mp[prev]++;
                }
            }

            if(!maxHeap.empty() && curr <= maxHeap.top()){
                maxHeap.push(curr);
                balance++;
            }else{
                minHeap.push(curr);
                balance--;
            }

            if(balance > 0){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else if(balance < 0){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            while(!maxHeap.empty() && mp[maxHeap.top()]){
                mp[maxHeap.top()]--;
                maxHeap.pop();
            }
            while(!minHeap.empty() && mp[minHeap.top()]){
                mp[minHeap.top()]--;
                minHeap.pop();
            }

        }

        double median;
        if(k % 2 == 0){
            median = ((1.0 * minHeap.top() + 1.0 * maxHeap.top()) / 2) ;
            ans.push_back(median);
        }else{
            median = 1.0 * maxHeap.top();
            ans.push_back(median);
        }

        return ans;
    }
};