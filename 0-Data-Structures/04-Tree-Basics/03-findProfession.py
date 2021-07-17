def findProfession(level, pos):
    if(level == 1):
        return "Engineer"
    parent = findProfession(level - 1, (pos+1) // 2)
    if(parent == "Engineer" and pos % 2 == 1):
        return "Engineer"
    if(parent == "Doctor" and pos % 2 == 0):
        return "Engineer"
    return "Doctor"

