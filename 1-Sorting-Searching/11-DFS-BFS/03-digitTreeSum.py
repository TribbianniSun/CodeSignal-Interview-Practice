#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None


def digitTreeSum(t):
    global_ret = 0
    def digitTreeSumHelper(t, s):
        nonlocal global_ret
        if t == None:
            return
        if t.left == None and t.right == None:
            global_ret += s * 10 + t.value   
            return
        if t.left:
            digitTreeSumHelper(t.left, s * 10 + t.value)
        if t.right:
            digitTreeSumHelper(t.right, s * 10 + t.value)
    digitTreeSumHelper(t, 0)
    return global_ret
        