# Interesting Solution using kirchhoff algorithm
# credit to roman_s10

import numpy as np

def det(M):
    L=len(M)
    for i in range(L-2):
        for j in range(i+1,L-1):
            for k in range(i+1,L-1):
                M[j][k]=M[j][k]*M[i][i] - M[j][i]*M[i][k]
                if i:
                    M[j][k] //= M[i-1][i-1]
    return M[-2][-2]

def hierarchiesCount(n, respectList):
    mod = 10**9+7
    if n == 1:
        return 1
    m = [[0] * n for i in range(n)]
    for (a,b) in respectList:
        m[a][b] = -1
        m[b][a] = -1
        m[a][a] += 1
        m[b][b] += 1
        
    C = det(m)
    return ((C % mod) * n) % mod