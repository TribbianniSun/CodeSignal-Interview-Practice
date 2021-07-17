# Note, use split wisely
def simplifyPath(path):
    
    pathList = path.split("/")
    myStack = []
    
    for pathStr in pathList:
        if pathStr == "." or len(pathStr) == 0:
            continue
        elif pathStr == "..":
            if len(myStack):
                myStack.pop()
        else:
            myStack.append(pathStr)
    
    return "/" + "/".join(myStack)
