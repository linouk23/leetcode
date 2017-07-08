# 372. Super Pow - https://leetcode.com/problems/super-pow


class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        power = 0
        for digit in b:
            power = 10 * power + digit
        result, cur_term = 1, a
        for bit in "".join(reversed(bin(power)[2:])):
            if (bit == '1'):
                result = (result % 1337) * (cur_term % 1337) % 1337
            cur_term = (cur_term % 1337) * (cur_term % 1337) % 1337
        return result
