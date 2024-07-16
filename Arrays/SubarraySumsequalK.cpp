from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        d = {0: 1}
        s = 0
        count= 0

        for i in nums:
            s+=i
            diff=s-k
            if diff in d:
                count+=d[diff]
            if s in d:
                d[s]+=1
            else:
                d[s]=1
        return count