# 360. Sort Transformed Array - https://leetcode.com/problems/sort-transformed-array

# Idea: https://discuss.leetcode.com/topic/48473/python-one-liner


class Solution:
    # Merge 2 sorted seq.
    def sortTransformedArray(self, nums, a, b, c):
        return sorted(a * x * x + b * x + c for x in nums)
