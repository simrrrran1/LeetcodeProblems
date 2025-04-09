class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int areaMax = 0;

        while(left < right){
            int h = min(height[left], height[right]);
            int w = right - left;
            int area = h * w;
            areaMax = max(area, areaMax);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return areaMax;
    }
};