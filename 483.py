# 483. Smallest Good Base - https://leetcode.com/problems/smallest-good-base


class Solution(object):
    def get_num(self, num_of_bits, base):
        result = 0
        power = 1
        for _ in range(num_of_bits):
            result += power
            power *= base
        return result

    def get_nth_root(self, number, n):
        L = 0
        R = number + 1
        while (R - L > 1):
            M = L + (R - L) / 2
            if pow(M, n) >= number:
                R = M
            else:
                L = M
        return R

    def bin_search(self, num_of_bits, number):
        L = 1
        R = self.get_nth_root(number, num_of_bits - 1)
        while (R - L > 1):
            M = L + (R - L) / 2
            if self.get_num(num_of_bits, M) >= number:
                R = M
            else:
                L = M
        return R

    def smallestGoodBase(self, n):
        number = int(n)
        for num_of_bits in reversed(range(1, 65)):
            base = self.bin_search(num_of_bits, number)
            lhs = pow(base, num_of_bits) - 1
            rhs = number * (base - 1)
            if lhs == rhs:
                return str(base)
        return ""

# 1*b^0 + 1*b + 1*b^2 + ... + 1*b^(n-1) = N, mult by base
# b + b^2 + ... + b^(n) = Nb
# b^(n) - 1 = N(b - 1)
