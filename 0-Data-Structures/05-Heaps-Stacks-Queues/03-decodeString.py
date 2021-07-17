def decodeString(s):
    myStack = [["", 1]]
    num = 0
    for c in s:
        if c == ']':
            item, time = myStack.pop()
            myStack[-1][0] += (time * item)
        elif c == '[':
            myStack.append(["", num])
            num = 0
        elif c.isnumeric():
            num = num * 10 + (ord(c) - ord('0'))
        else:
            myStack[-1][0] += c
    
    return myStack[-1][0]