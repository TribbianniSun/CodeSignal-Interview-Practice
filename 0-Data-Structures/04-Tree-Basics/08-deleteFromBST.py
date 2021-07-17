def deleteFromBST(t, queries):        
    def deleteFromBSTHelper(node, root, query):
        if node == None:
            return
        if node.value == query:
            if node.left == None:
                if root.left == node:
                    root.left = node.right
                else:
                    root.right = node.right
            else:
                rightMostNode = findRightMost(node.left, node)
                rightMostNode.right = node.right
                if node.left !=  rightMostNode:
                    rightMostNode.left = node.left
                if root.left == node:
                    root.left = rightMostNode
                else:
                    root.right = rightMostNode
        elif node.value > query:
            deleteFromBSTHelper(node.left, node, query)
        else:
            deleteFromBSTHelper(node.right, node, query)

    def findRightMost(node, root):
        if node.right == None:
            if(root.right == node):
                root.right = node.left
            return node
        else:
            if(root.left == node):
                return findRightMost(node.right, root.left)
            else:
                return findRightMost(node.right, root.right)
            
    dummy = Tree(-2e9)
    dummy.left = t
    for key in queries:
        deleteFromBSTHelper(dummy.left, dummy, key)
    return dummy.left