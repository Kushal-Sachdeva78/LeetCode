class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_map = {}  # stores num -> index
        for i, num in enumerate(nums):
            complement = target - num
            if complement in index_map:
                return [index_map[complement], i]
            index_map[num] = i
