class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        if not s or not words: return []
        w, m, n = len(words[0]), len(words), len(s)
        total, count = w * m, {}
        for word in words:
            count[word] = count.get(word, 0) + 1
        res = []
        for i in range(w):
            left = i
            seen = {}
            matched = 0
            for j in range(i, n - w + 1, w):
                t = s[j:j+w]
                if t in count:
                    seen[t] = seen.get(t, 0) + 1
                    if seen[t] <= count[t]:
                        matched += 1
                    while seen[t] > count[t]:
                        l = s[left:left+w]
                        seen[l] -= 1
                        if seen[l] < count[l]:
                            matched -= 1
                        left += w
                    if matched == m:
                        res.append(left)
                        l = s[left:left+w]
                        seen[l] -= 1
                        matched -= 1
                        left += w
                else:
                    seen.clear()
                    matched = 0
                    left = j + w
        return res
