class Solution:
    def letterCombinations(self, digits):
        if not digits:
            return []
        mp = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }
        res = []

        def backtrack(i, path):
            if i == len(digits):
                res.append(path)
                return
            for c in mp[digits[i]]:
                backtrack(i + 1, path + c)

        backtrack(0, "")
        return res
