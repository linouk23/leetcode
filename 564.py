# 564. Find the Closest Palindrome - https://leetcode.com/problems/find-the-closest-palindrome

# Credits to
# https://discuss.leetcode.com/topic/87220/python-simple-with-explanation


class Solution(object):

    def nearestPalindromic(self, S):
        K = len(S)
        candidates = [str(10**k + d) for k in (K - 1, K) for d in (-1, 1)]
        prefix = S[:(K + 1) / 2]
        P = int(prefix)
        for start in map(str, (P - 1, P, P + 1)):
            candidates.append(start + (start[:-1] if K % 2 else start)[::-1])

        def delta(x):
            return abs(int(S) - int(x))

        result = None
        for cand in candidates:
            if cand != S and not cand.startswith('00'):
                if (result is None or delta(cand) < delta(result) or
                        delta(cand) == delta(result) and int(cand) < int(result)):
                    result = cand
        return result
