class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums1[i]] = i;
        }
        vector<int> v(n, -1);
        stack<int> s;
        for(int i=0; i<m; i++){
            while(!s.empty() && nums2[s.top()] < nums2[i]){
                int topIdx = s.top();
                s.pop();
                if(mp.find(nums2[topIdx]) == mp.end()) continue;
                int idx = mp[nums2[topIdx]];
                v[idx] = nums2[i];
                
            }
            s.push(i); 
        }
        return v;
    }
};