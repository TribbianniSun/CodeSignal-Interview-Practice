#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def deleteFromBST(t, queries):

    def findRightMostNode(focusingNode, parent):
        # found the rightMostNode
        if focusingNode.right == None:
            parent.right = focusingNode.left
            return focusingNode
        else:
            return findRightMostNode(focusingNode.right, focusingNode)
    
    def updateNode(oldNode, newNode, parent):
        if parent.left == oldNode:
            parent.left = newNode
        else:
            parent.right = newNode
    
    
    def deleteFromBSTHelper(node, root, query):
        if node == None:
            return 
        if node.value == query:
            if node.left == None:
                updateNode(node, node.right, root)
            else:
                leftNode = node.left
                if leftNode.right == None:
                    leftNode.right = node.right
                    updateNode(node, leftNode, root)
                else:
                    rightMostNode = findRightMostNode(node.left, node)
                    rightMostNode.right = node.right
                    rightMostNode.left = node.left
                    updateNode(node, rightMostNode, root)
        
        elif node.value > query:
            deleteFromBSTHelper(node.left, node, query)
        else:
            deleteFromBSTHelper(node.right, node, query)
    
    dummy = Tree(-2e9)
    dummy.left = t
    for q in queries:
        deleteFromBSTHelper(dummy.left, dummy, q)
    return dummy.left
            
