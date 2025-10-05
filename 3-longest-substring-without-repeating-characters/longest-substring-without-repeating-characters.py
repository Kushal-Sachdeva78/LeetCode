class Solution:
    def lengthOfLongestSubstring(self, s):
        seen = {}
        left = 0
        best = 0
        for right, ch in enumerate(s):
            if ch in seen and seen[ch] >= left:
                left = seen[ch] + 1
            seen[ch] = right
            cur = right - left + 1
            if cur > best:
                best = cur
        return best
