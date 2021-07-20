# Interesting Solution
# Nice Representation
# https://web.stanford.edu/class/cs97si/04-dynamic-programming.pdf
def fillingBlocks(n):
    if(n == 1):
        return 1
    f = [1, 5] # 1111
    a = [1, 2] # 1100 | 0011
    b = [1, 1] # 0110
    
    for i in range(3, n + 1):
        an = f[-1] + a[-1]
        bn = f[-1] + b[-2]
        fn = f[-2] + b[-1] + an + a[-1]
        f.append(fn)
        b.append(bn)
        a.append(an)
    return f[-1]