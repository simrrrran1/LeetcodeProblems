class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        //if(size1 == 0) return nums2[(size2-1)/2];
        //if(size2 == 0) return nums1[(size1-1)/2];

        if(size1 < size2) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = size2*2;

        while(low <= high){

            int mid1 = (low + high)/2; //cut1
            int mid2 = size1 + size2 - mid1; // cut2 

            double left1 = (mid2 == 0) ? INT_MIN : nums1[(mid2-1)/ 2];
            double left2 = (mid1 == 0) ? INT_MIN : nums2[(mid1-1)/2];
            double right1 = (mid2 == size1*2) ? INT_MAX : nums1[mid2/2];
            double right2 = (mid1 == size2*2) ? INT_MAX :nums2[mid1/2];

            if(left1 > right2) low = mid1+1;
            else if(left2 > right1) high = mid1-1;
            else return (max(left1,left2) + min(right1,right2))/2;

        }
        return -1;

    }

    // [1,2,3]
    // [4,5,6]
    // [1,2,3,4,5,6]

    //[1,2,5]
    //[2,3,4]
    //[1,2,2,3,4,5]

    //[1,2,3,4,5]
    //[6,7,8,9,10,11,12,13,14,15,16,17]

    //[6,7,8,9,10,11,12,13,14,15,16,17]

//     high = 10, low 
//     mid1 =5, mid2 =17
// 8+2/2=5
//     left1 =8, left2 =4
//     right1 =8 , right2 =2
};