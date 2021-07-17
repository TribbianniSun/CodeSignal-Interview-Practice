#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None



def restoreBinaryTree(inorder, preorder):
    

    # preorder will know the root of the binary tree
    # find its index in inorder, and partition the inorder into two parts
    
    mp = {}
    for i in range(len(inorder)):
        num = inorder[i]
        mp[num] = i
    
    def restoreBinaryTreeHelper(il, ir, pl, pr):
        if il > ir or pl > pr:
            return None
        if il == ir:
            return Tree(inorder[il])
        
        root = Tree(preorder[pl])
        idx = mp[root.value]
        numberOfNodesOnLeft = idx - il
        root.left = restoreBinaryTreeHelper(il, idx - 1, pl + 1, pl + numberOfNodesOnLeft)
        root.right = restoreBinaryTreeHelper(idx + 1, ir, pl + numberOfNodesOnLeft + 1, pr)
        
        return root


    return restoreBinaryTreeHelper(0, len(preorder) - 1, 0, len(preorder) - 1)
        


        