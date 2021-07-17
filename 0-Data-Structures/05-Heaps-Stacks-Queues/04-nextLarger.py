def nextLarger(a):
    myStack = []
    ret = [-1 for _ in range(len(a))]
    for i in range(len(a) - 1, -1, -1):
        while(len(myStack) and a[myStack[-1]] <= a[i]):
            myStack.pop()
        if(len(myStack)):
            ret[i] = a[myStack[-1]]
        myStack.append(i)
    return ret 



