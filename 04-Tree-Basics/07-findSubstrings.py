# Interesting Solution credit to 
# https://app.codesignal.com/interview-practice/task/Ki9zRh5bfRhH6oBau/solutions?solutionId=MH6fXYf5rz44zdqHy

# 5 * 30 * 10^å4


class TrieTree(object):

    # how he build the tree is jsut amazing
    def __init__(self):
        self.children = {}
        self.isWord = False

    def insertWord(self, word):
        if not word:
            self.isWord = True
        else:
            self.children.setdefault(ord(word[0]), TrieTree()).insertWord(word[1:])
        
            # words[i] = "%s[%s]%s" % (w[:pos], w[pos:pos+L], w[pos+L:])
            
    def customSearch(self, w):
        pos = len(w)
        L = -1
        for j in range(len(w)):
            t = self
            k = j
            while k < len(w) and ord(w[k]) in t.children:
                t = t.children[ord(w[k])]
                k += 1
                if t.isWord and k - j > L:
                    L = k - j
                    pos = j
        
        if L > 0:
            return [pos, pos + L]
        return []

def findSubstrings(words, parts):
    
    # step1, build the trie tree
    myTrieTree = TrieTree()
 
    for i, part in enumerate(parts):
        myTrieTree.insertWord(part)
    
            
            
    # step2, for each index, try to find the result
    
    for i, word in enumerate(words):
        ret = myTrieTree.customSearch(word)
        if(len(ret) == 0):
            continue
        else:
            idx1 = ret[0]
            idx2 = ret[1]
            words[i] = "%s[%s]%s" % (word[:idx1], word[idx1:idx2], word[idx2:])
    
    return words
    

# Another implementation for the same idea
# We can learn a lot from the implementation given by k_lee

'''
class Node(object):
    def __init__(self, done = False):
        self.isWord = done
        self.children = [None for _ in range(300)]
    
class TrieTree(object):
    
    def __init__(self):
        self.root = Node()
            
    def insertWord(self, word, focusingIdx):
            
        def insertWordHelper(idx, node):
            if idx == len(word):
                return
            else:
                charIdx = ord(word[idx])
                if node.children[charIdx] == None:
                    node.children[charIdx] = Node(idx == len(word) - 1)
                node.children[charIdx].isWord = idx == len(word) - 1
                insertWordHelper(idx + 1, node.children[charIdx])
        
        return insertWordHelper(0, self.root)
        
        
    def customSearch(self, word):
        ret = []
        def customSearchHelper(startIdx, idx, node):
            nonlocal ret
            if node.isWord:
                if len(ret) == 0:
                    ret = [startIdx, idx, idx - startIdx]
                elif ret[2] < idx - startIdx:
                    ret = [startIdx, idx, idx - startIdx]
                    
            if idx == len(word):
                return
            if node == None:
                return
            charIdx = ord(word[idx])
                    
            if node.children[charIdx] == None:
                return
            
            customSearchHelper(startIdx, idx + 1, node.children[charIdx])
            
                
        for i in range(len(word)):
            customSearchHelper(i, i, self.root)
        
        
        return ret
        
            
            
            


def findSubstrings(words, parts):
    
    # step1, build the trie tree
    myTrieTree = TrieTree()
 
    for i, part in enumerate(parts):
        myTrieTree.insertWord(part, i)
    
            
            
    # step2, for each index, try to find the result
    
    global_ret = []
    
    for word in words:
        ret = myTrieTree.customSearch(word)
        if(len(ret) == 0):
            global_ret.append(word)
        else:
            global_ret.append(word[:ret[0]] + '[' + word[ret[0]:ret[1]] + ']' + word[ret[1]:])
            
    return global_ret
'''