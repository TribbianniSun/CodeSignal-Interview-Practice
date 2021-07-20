def listToString(arr):
    arr = [str(i) for i in arr]
    focus = " ".join(arr)
    focus = "({})".format(focus)
    return focus
    

def combinationSum(a, target):
    a = sorted(list(set(a)))
    a = a[::-1]
    global_ret = []
    
    def dfs(path, u, start):
        nonlocal global_ret
        nonlocal target
        if(u == target):
            global_ret.append(sorted(list(path)))
            return
        if(u > target):
            return
        if(start == len(a)):
            return
        # not take this 
        dfs(path, u, start + 1)
        

        path.append(a[start])
        dfs(path, u + a[start], start)
        path.pop()     
            
    dfs([], 0, 0);
    global_ret = sorted(global_ret)
    processed_ret = [listToString(s) for s in global_ret]
    if(len(processed_ret)):
        return "".join(processed_ret)
    else:
        return "Empty"