class Solution(object):
    def process(self, token, op1, op2):
        eval_methods = {
                            "+": lambda x, y: x+y, 
                            "-": lambda x, y: x-y,
                            "*": lambda x, y: x*y,
                            "/": lambda x, y: int(x/float(y)),                            
                        }
        return eval_methods[token](op1, op2)
    
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        st = []
        for token in tokens:
            if token in set(["+", "-", "*", "/"]):
                op2 = st.pop()
                op1 = st.pop()
                result = self.process(token, op1, op2)
                st.append(result)
            else:
                st.append(int(token))
        return st.pop()