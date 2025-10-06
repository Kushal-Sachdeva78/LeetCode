class Solution:
    def romanToInt(self, s):
        values = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        
        total = 0
        prev_value = 0
        
        for ch in reversed(s):  
            curr = values[ch]
            if curr < prev_value:
                total -= curr
            else:
                total += curr
            prev_value = curr
            
        return total


s = Solution()
print(s.romanToInt("III"))      
print(s.romanToInt("LVIII"))    
print(s.romanToInt("MCMXCIV"))  
