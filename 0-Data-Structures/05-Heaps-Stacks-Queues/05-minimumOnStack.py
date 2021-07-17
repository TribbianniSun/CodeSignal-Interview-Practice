
def minimumOnStack(operations):
    myStack = []
    ret = []
    global_min = 2e9
    for op in operations:
        opList = op.split(" ")
        if(len(opList) == 1):
            if(op == "pop"):
                poppdeItem = myStack.pop()
                if poppdeItem == global_min:
                    global_min = myStack.pop() 
            elif (op == "min"):
                ret.append(global_min)
        else:
            num = int(opList[1])
            if(num <= global_min):
                myStack.append(global_min)
                myStack.append(num)
                global_min = num
            else:
                myStack.append(num)
    return ret