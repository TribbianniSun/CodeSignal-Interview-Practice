def nearestGreater(a):
    n = len(a)
    ret = [-1 for _ in range(len(a))]
    myStack = []
    for i, num in enumerate(a):
        while(len(myStack) and a[myStack[-1]] < num):
            # num is greater than myStack[-1]
            ret[myStack[-1]] = i
            myStack.pop()
        myStack.append(i)
    
    myStack = []
    for i in range(len(a) - 1, -1, -1):
        num = a[i]
        while(len(myStack) and a[myStack[-1]] < num):
            if ret[myStack[-1]] == -1:
                ret[myStack[-1]] = i
            elif abs(i - myStack[-1]) <= abs(ret[myStack[-1]] - myStack[-1]):
                ret[myStack[-1]] = i
            myStack.pop()
        myStack.append(i)
    
    return ret
            