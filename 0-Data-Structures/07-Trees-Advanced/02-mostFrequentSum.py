#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def mostFrequentSum(t):
    
    mp = {} # sum -> frequency
    
    
    def dfs(focusingNode):
        nonlocal mp
        if focusingNode == None:
            return 0
        
        l = dfs(focusingNode.left)
        r = dfs(focusingNode.right)
        c_s = l + r + focusingNode.value
        if c_s in mp:
            mp[c_s] += 1
        else:
            mp[c_s] = 1
        return c_s
    
    # init
    dfs(t)
    
    max_freq = 0
    ret = []
    for s in mp:
        freq = mp[s]
        if freq == max_freq:
            ret.append(s)
        elif freq > max_freq:
            max_freq = freq
            ret = [s]
    
    return sorted(ret)
