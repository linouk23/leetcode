# 636. Exclusive Time of Functions - https://leetcode.com/problems/exclusive-time-of-functions


class Solution:
    def exclusiveTime(self, N, logs):
        """
        :type N: int
        :type logs: List[str]
        :rtype: List[int]
        """
        ans = [0] * N
        # Keep id of functions in this stack
        stack = []
        # Separate counter to track time
        prev_time = 0

        for log in logs:
            id, type, time = log.split(':')
            id, time = int(id), int(time)

            if type == 'start':
                if stack:
                    ans[stack[-1]] += time - prev_time
                stack.append(id)
                prev_time = time
            else:
                ans[stack.pop()] += time - prev_time + 1
                prev_time = time + 1

        return ans
