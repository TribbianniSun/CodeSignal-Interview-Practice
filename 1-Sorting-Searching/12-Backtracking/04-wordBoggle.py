
class Trie(object):
    def __init__(self):
        self.words = []
        self.end = False
        self.children = {}
    
    def add(self, focusingWord, idx):
        if len(focusingWord) == 0:
            self.end = True
            self.words.append(idx)
            return
        c = focusingWord[0]
        if c in self.children:
            self.children[c].add(focusingWord[1:], idx)
        else:
            self.children[c] = Trie()
            self.children[c].add(focusingWord[1:], idx)
    
def wordBoggle(board, words):   
    
    
    # step1, build the trie
    myTrie = Trie()
    for idx, word in enumerate(words):
        myTrie.add(word, idx)
    
    n = len(board)
    m = len(board[0])
    
    global_ret = [False for _ in range(len(words))]
    
    def dfs(i, j, node):
        nonlocal global_ret
        c = board[i][j]
        if c in node.children:
            
            board[i][j] = '.'
            
            if(node.children[c].end):
                for idx in node.children[c].words:
                    global_ret[idx] = True
                    
            for ii in range(-1, 2, 1):
                for jj in range(-1, 2, 1):
                    ni = i + ii
                    nj = j + jj
                    if (ni < 0 or ni >= n or nj < 0 or nj >= m):
                        continue
                    if board[ni][nj] == '.':
                        continue
                    if c == 'A' and board[0][0] == '.':
                        print(ni, nj)
                    dfs(ni, nj, node.children[c])
            board[i][j] = c
        
        
    for i in range(n):
        for j in range(m):
            dfs(i, j, myTrie)
            
    ret = []
    for i in range(len(global_ret)):
        if(global_ret[i]):
            ret.append(words[i])
        
    return sorted(ret)