#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None

def isSameTree(t1, t2):
    if(t1 == None):
        return t2 == None
    if(t2 == None):
        return t1 == None
    if(t1.value == t2.value):
        return isSameTree(t1.left, t2.left) and isSameTree(t1.right, t2.right)
    return False

def isSubtree(t1, t2):
    if(t1 == None):
        return t2 == None
    if(t2 == None):
        return True
    if(t1.value == t2.value):
        return isSameTree(t1, t2)
    return isSubtree(t1.left, t2) or isSubtree(t1.right, t2)



# Interesting Solution credit to 
# https://leetcode.com/problems/subtree-of-another-tree/discuss/102741/Python-Straightforward-with-Explanation-(O(ST)-and-O(S%2BT)-approaches)



# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def isSubtree(t1, t2):
    
    from hashlib import sha256
    
    def hash_(x):
        S = sha256()
        S.update(bytes(x, encoding='utf-8'))
        return S.hexdigest()
        
    def merkle(node):
        if not node:
            return '*'
        
        l = merkle(node.left)
        r = merkle(node.right)
        node.merkle = hash_(l + str(node.value) + r)
        return node.merkle
    
    
    merkle(t1), merkle(t2)
    
    def dfs(s, t):
        if not t:
            return True
        if not s:
            return False
        return s.merkle == t.merkle or dfs(s.left, t) or dfs(s.right, t)
    
    
    return dfs(t1, t2)