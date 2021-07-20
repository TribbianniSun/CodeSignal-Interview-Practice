#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None

import collections

def traverseTree(t):
    ret = []
    if not t:
        return ret
    myQueue = collections.deque()
    myQueue.append(t)
    while len(myQueue):
        cur = myQueue.popleft()
        if not cur:
            continue
        ret.append(cur.value)
        myQueue.append(cur.left)
        myQueue.append(cur.right)
    return ret