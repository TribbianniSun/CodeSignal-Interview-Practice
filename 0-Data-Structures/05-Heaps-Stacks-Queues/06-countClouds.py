def countClouds(skyMap):
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    n = len(skyMap)
    if n == 0:
        return 0
    m = len(skyMap[0])
    counter = 0
    def dfs(i, j):
        if i < 0 or i >= n or j < 0 or j >= m:
            return
        if skyMap[i][j] != '1':
            return
        skyMap[i][j] = '2'
        for k in range(len(dx)):
            dfs(i + dx[k], j + dy[k])
    
    
    for i in range(n):
        for j in range(m):
            if(skyMap[i][j] == '1'):
                dfs(i, j)
                counter += 1
                
    return counter