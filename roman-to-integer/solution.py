class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        ro = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        n =len(s)
        ans =0
        for i in range(n-1):
            if(ro[s[i+1]] > ro[s[i]]):
                ans += -ro[s[i]]
            else:
                ans += ro[s[i]]
        return ans + ro[s[n-1]]