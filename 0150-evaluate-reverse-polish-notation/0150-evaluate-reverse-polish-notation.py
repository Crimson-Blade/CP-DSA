class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operations = {
            '+': lambda x, y: x + y,
            '-': lambda x, y: x - y,
            '*': lambda x, y: x * y,
            '/': lambda x, y: x / y if y != 0 else 'undefined'
        }
        for t in tokens:
            if t in operations:
                x = stack[-2]
                y = stack[-1]
                stack.pop()
                stack.pop()
                z = operations[t](int(x),int(y))
                stack.append(z)
            else:
                stack.append(t)
        return int(stack[-1])
            