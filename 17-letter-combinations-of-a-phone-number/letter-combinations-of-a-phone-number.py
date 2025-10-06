from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        mapping = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }
        
        res = []

        def backtrack(index: int, path: str):
            if index == len(digits):
                res.append(path)
                return
            for c in mapping[digits[index]]:
                backtrack(index + 1, path + c)

        backtrack(0, "")
        return res
