class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        ss=s.split()
        ss=ss[::-1]
        return ' '.join(ss)
       