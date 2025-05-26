class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        // for(int i=n-1; i>=0; i--){
        //     for(int j=1; j<=i; j++){
        //         nums[j-1] += nums[j];
        //         nums[j-1] = nums[j-1] % 10;
        //         cout<< nums[j-1] << " ";
        //     }
        //     cout<< endl;
        // }

        while(nums.size() > 1){

            for(int i=0; i<nums.size()-1; i++){
                nums[i] = (nums[i]+nums[i+1]) % 10;
            }
            nums.pop_back();
        }
        return nums[0];
    }

//     int triangularSum(vector<int>& nums) {
//     // int result = 0;
//     // int m = nums.size() - 1;
//     // int mck = 1, exp2 = 0, exp5 = 0;
//     // int inv[] = {0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
//     // int pow2mod10[] = {6, 2, 4, 8};        
//     // for (int k = 0; true; k++) {
//     //     if (!exp2 || !exp5) {
//     //         int mCk_ = exp2 ? mck * pow2mod10[exp2 % 4] :
//     //                    exp5 ? mck * 5 : mck;
//     //         result = (result + mCk_ * nums[k]) % 10;
//     //     }
//     //     if (k == m)
//     //         return result;

//     //     // mCk *= m - k
//     //     int mul = m - k;
//     //     while (mul % 2 == 0) {
//     //         mul /= 2;
//     //         exp2++;
//     //     }
//     //     while (mul % 5 == 0) {
//     //         mul /= 5;
//     //         exp5++;
//     //     }
//     //     mck = mck * mul % 10;

//     //     // mCk /= k + 1
//     //     int div = k + 1;
//     //     while (div % 2 == 0) {
//     //         div /= 2;
//     //         exp2--;
//     //     }
//     //     while (div % 5 == 0) {
//     //         div /= 5;
//     //         exp5--;
//     //     }
//     //     mck = mck * inv[div % 10] % 10;
//         // int n = nums.size();
//         // long long choose = 1;
//         // long long total = 0;
//         // for(int i=0; i<n; i++){
//         //     total += (nums[i] * choose);
//         //     choose = choose * ((n-1) - i);
//         // }
//         // return (int)total%10;
// }
};