# 469. Convex Polygon - https://leetcode.com/problems/convex-polygon


class Solution(object):
    def isConvex(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        def direction(a, b, c):
            return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])

        d = 0
        n = len(points)

        for idx in range(n):
            a = direction(points[idx], points[(idx + 1) % n], points[(idx + 2) % n])
            if a:
                if not d:
                    d = a
                elif a * d < 0:
                    return False

        return True
