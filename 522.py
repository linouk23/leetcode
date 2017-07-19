# 522. Longest Uncommon Subsequence II - https://leetcode.com/problems/longest-uncommon-subsequence-ii


class Solution(object):
    def subseq(self, w1, w2):
        #True iff word1 is a subsequence of word2.
        i = 0
        for c in w2:
            if i < len(w1) and w1[i] == c:
                i += 1
        return i == len(w1)

    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """

        strs.sort(key=len, reverse=True)
        for i, word1 in enumerate(strs):
            if all(not self.subseq(word1, word2) 
                    for j, word2 in enumerate(strs) if i != j):
                return len(word1)
        return -1
