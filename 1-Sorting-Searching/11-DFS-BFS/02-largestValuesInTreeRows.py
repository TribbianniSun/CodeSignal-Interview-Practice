#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
import collections
def largestValuesInTreeRows(t):
    ret = []
    if not t:
        return ret
    myQueue = collections.deque()
    myQueue.append(t)
    while(len(myQueue)):
        size = len(myQueue)
        local_ret = -2e9
        for i in range(size):
            cur = myQueue.popleft()
            local_ret = max(local_ret, cur.value)
            if cur.left:
                myQueue.append(cur.left)
            if cur.right:
                myQueue.append(cur.right)
        ret.append(local_ret)
    return ret
                