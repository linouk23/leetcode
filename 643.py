# 643. Maximum Average Subarray I - https://leetcode.com/problems/maximum-average-subarray-i


class Solution:
    def findMaxAverage(self, nums, k):
        sums = [0] + list(itertools.accumulate(nums))
        return max(map(operator.sub, sums[k:], sums)) / k
