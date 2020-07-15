"""
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

输入: "()[]{}"
输出: true

输入: "([)]"
输出: false

思路：栈stack的思想，先入后出
利用堆栈后进先出的特点，遇到左括号就压入栈内，遇到右括号时，判断右括号与栈顶元素是否匹配（右括
号不能进栈）。若匹配则pop出栈顶的左括号，继续遍历。不匹配则返回false。直到遍历结束后，栈内的左括
号应完全弹出才返回true。

pop() 函数用于移除列表中的一个元素（默认最后一个元素），并且返回该元素的值。
"""

class Solution:
    def isValid(self, s):
        dic = {'{': '}',  '[': ']', '(': ')', '?': '?'}
        if not s:
            return True
        stack = ['?']
        for c in s:
            if c in dic:  # 这里判断的是字典dic的key值
                stack.append(c)
            elif dic[stack.pop()] != c: 
                return False 
        return len(stack) == 1



                
