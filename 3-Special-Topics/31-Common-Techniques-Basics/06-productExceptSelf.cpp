// https://blueblazin.github.io/codefighter/commontechniques/2017/12/19/productExceptSelf.html



// 
// s2 = a + b
// p2 = ab

// s3 = ab + bc + ac = s2 * num[3] + p2
// p3 = abc = p2 * num[3]

def productExceptSelf(nums, m):
    s = [0]
    p = [1]
    for num in nums:
        sn = (s[-1] * num + p[-1]) % m
        pn = (p[-1] * num) % m
        s.append(sn)
        p.append(pn)
    return s[-1]
        


