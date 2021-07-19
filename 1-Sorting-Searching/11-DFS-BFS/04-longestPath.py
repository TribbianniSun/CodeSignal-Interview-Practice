# Interesting Solution credit to chris_s94
def longestPath(fileSystem):
    maxlen = 0
    pathlen = {0:0}
    for line in fileSystem.splitlines():
        print(line)
        name = line.lstrip('\t')
        depth = len(line)-len(name)
        if '.' in name:
            maxlen = max(maxlen, pathlen[depth]+len(name))
        else:
            pathlen[depth+1] = pathlen[depth] + len(name)+1
    return maxlen