# 591. Tag Validator - https://leetcode.com/problems/tag-validator

# Credits to
# https://discuss.leetcode.com/topic/91381/short-python-accepted-but-not-sure-if-correct

class Solution:
    def isValid(self, code):
        code = re.sub(r'<!\[CDATA\[.*?\]\]>|t', '-', code)
        prev = None
        while code != prev:
            prev = code
            code = re.sub(r'<([A-Z]{1,9})>[^<]*</\1>', 't', code)
        return code == 't'
