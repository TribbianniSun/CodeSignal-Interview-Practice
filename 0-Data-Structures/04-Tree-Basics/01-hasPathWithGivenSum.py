#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None



def hasPathWithGivenSum(t, s):
    
    if(t == None):
        return False
    
    if(t.left == None and t.right == None):
        return t.value == s
    
    l = hasPathWithGivenSum(t.left, s - t.value)
    r = hasPathWithGivenSum(t.right, s - t.value)
    
    return l or r
    