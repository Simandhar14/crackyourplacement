class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack=[]
        res=[]
        def backtrack(openN,closed):
            if openN==closed==n:
                res.append("".join(stack))
                return 
            if openN<n:
                stack.append("(")
                backtrack(openN+1,closed)
                stack.pop()
            if closed<openN:
                stack.append(")")
                backtrack(openN,closed+1)
                stack.pop()
        backtrack(0,0)
        return res
        