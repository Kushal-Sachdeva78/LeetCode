class Solution:
    def countAndSay(self, n):
        s = "1"
        for _ in range(n - 1):
            res = ""
            count = 1
            for i in range(1, len(s) + 1):
                if i < len(s) and s[i] == s[i - 1]:
                    count += 1
                else:
                    res += str(count) + s[i - 1]
                    count = 1
            s = res
        return s
