class Solution:
    def intToRoman(self, num):
        values = [
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4,
            1
        ]
        symbols = [
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV",
            "I"
        ]
        
        roman = ""
        for i in range(len(values)):
            while num >= values[i]:
                num -= values[i]
                roman += symbols[i]
        return roman


# Example usage:
s = Solution()
print(s.intToRoman(3749))  # MMMDCCXLIX
print(s.intToRoman(58))    # LVIII
print(s.intToRoman(1994))  # MCMXCIV
