#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def kthSmallestInBST(t, k):
    ret = 0
    def dfs(node, k):
        nonlocal ret
        if(node == None):
            return 0
        l = dfs(node.left, k)
        k -= l
        if(k == 1):
            ret = node.value
        r = dfs(node.right, k - 1)
        return 1 + l + r
    
    dfs(t, k)
    return ret
        
## Interesting Solution credit to 
# https://app.codesignal.com/interview-practice/task/jAKLMWLu8ynBhYsv6/solutions?solutionId=KfrWi2pBCmcFSDPfY

# Definition for binary tree:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def kthSmallestInBST(t, k):
    # Morris in-order traversal (O(1) memory usage)
    # https://www.youtube.com/watch?v=wGXB9OWhPTg explains this pretty well
    
    current = t
    
    while current:
        if not current.left:
            k -= 1
            if k == 0:
                return current.value
            
            current = current.right
        else:
            predecessor = find_predecessor(current)
            if not predecessor.right:
                predecessor.right = current
                current = current.left
            else:
                predecessor.right = None
                k -= 1
                if k == 0:
                    return current.value
                current = current.right
                
                
    return None
         
def find_predecessor(t):
    # Go left once, then right as much times as possible
    predecessor = t.left
    
    while predecessor.right and predecessor.right != t:
        predecessor = predecessor.right
        
    return predecessor