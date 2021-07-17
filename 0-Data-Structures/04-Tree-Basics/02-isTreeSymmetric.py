#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def isTreeSymmetric(t):
    
    # edge case check
    if(t == None):
        return True
        
    def checkMirror(l, r):
        if l == None:
            return r == None
        if r == None:
            return l == None
        if l.value != r.value:
            return False
        
        return checkMirror(l.right, r.left) and checkMirror(l.left, r.right)

    return checkMirror(t.left, t.right)
