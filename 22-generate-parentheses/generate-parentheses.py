from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def dfs(open_cnt: int, close_cnt: int, cur: str):
            if len(cur) == 2 * n:
                res.append(cur)
                return
            if open_cnt < n:
                dfs(open_cnt + 1, close_cnt, cur + "(")
            if close_cnt < open_cnt:
                dfs(open_cnt, close_cnt + 1, cur + ")")
        dfs(0, 0, "")
        return res
