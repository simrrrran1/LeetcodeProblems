class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = {0: 1}
        sum = 0
        ans = 0
        
        for i in nums:
            sum += i
            ans += mp.get(sum-k, 0)
            mp[sum] = 1 + mp.get(sum, 0)

        return ans



