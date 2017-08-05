# 164. Maximum Gap - https://leetcode.com/problems/maximum-gap
# Original, unsorted list:
# 170, 45, 75, 90, 802, 2, 24, 66
# Sorting by least significant digit (1s place) gives:
# 170, 90, 802, 2, 24, 45, 75, 66
# Notice that we keep 802 before 2, because 802 occurred before 2 in the original list, and similarly for pairs 170 & 90 and 45 & 75.
# Sorting by next digit (10s place) gives:
# 802, 2, 24, 45, 66, 170, 75, 90
# Notice that 802 again comes before 2 as 802 comes before 2 in the previous list.
# Sorting by most significant digit (100s place) gives:
# 2, 24, 45, 66, 75, 90, 170, 802

# Take the least significant digit (or group of bits, both being examples of radices) of each key.
# Group the keys based on that digit, but otherwise keep the original order of keys. (This is what makes the LSD radix sort a stable sort.)
# Repeat the grouping process with each more significant digit.
# The sort in step 2 is usually done using bucket sort or counting sort, which are efficient in this case since there are usually only a small number of digits.

# https://en.wikipedia.org/wiki/Radix_sort


class Solution:
    def maximumGap(self, num):
        if len(num) < 2:
            return 0
        num = self.radixSort(num)
        res = 0
        for i in range(1, len(num)):
            res = max(num[i] - num[i - 1], res)
        return res

    def radixSort(self, num):
        for i in range(31):
            onebucket = []
            zerobucket = []
            order = 1 << i
            for lsd_bit in range(len(num)):
                if num[lsd_bit] & order != 0:
                    onebucket.append(num[lsd_bit])
                else:
                    zerobucket.append(num[lsd_bit])
            num = []
            num += zerobucket
            num += onebucket
        return num