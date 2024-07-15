class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)-1):
            j=i+1
            sums=0
            while j<len(nums):
              sums=nums[i]+nums[j]
              if sums==target:
                 lst=[i,j]
                 return lst
              j+=1
            
        