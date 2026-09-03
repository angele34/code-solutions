class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {")": "(", "]": "[", "}": "{"}
        
        for i in s:
            if i == '(' or i == '[' or i == '{':
                stack.append(i)
            if i == ')' or i == ']' or i == '}':
                if len(stack) > 0 and stack[-1] == mapping[i]:
                    stack.pop()
                else: 
                    return False

        if len(stack) == 0:
            return True
        return False
