class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        out = [-1, -1]
        obj = {}

        for i in range(len(nums)):
            diff = target - nums[i]
            
            if diff in obj and i != obj[diff]:
                out[0] = i
                out[1] = obj[diff]
                
                return out
            else:
                obj[nums[i]] = i
        
        return out
