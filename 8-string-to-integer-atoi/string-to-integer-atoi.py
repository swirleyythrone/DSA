class Solution:
    def myAtoi(self, s: str) -> int:
        sign = 1
        i = 0
        ans = 0
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        # Skip leading whitespaces
        while i < len(s) and s[i] == ' ':
            i += 1

        # Handle sign
        if i < len(s) and s[i] == '-':
            sign = -1
            i += 1
        elif i < len(s) and s[i] == '+':
            i += 1

        # Convert digits and handle overflow
        while i < len(s) and s[i].isdigit():
            ans = ans * 10 + int(s[i])
            if ans > INT_MAX:
                return INT_MIN if sign == -1 else INT_MAX
            i += 1

        return sign * ans
