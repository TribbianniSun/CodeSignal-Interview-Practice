 # Singly-linked lists are already defined with this interface:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def addTwoHugeNumbers(a, b):
    reversedA = reverseLinkedList(a)
    reversedB = reverseLinkedList(b)
    carry = 0
    dummy = ListNode(-1)
    tail = dummy
    while(reversedA or reversedB or carry):
        focusingA = reversedA.value if reversedA else 0
        focusingB = reversedB.value if reversedB else 0
        focusingSum = focusingA + focusingB + carry
        carry = focusingSum // 10000
        cur = focusingSum % 10000
        tail.next = ListNode(cur)
        print(focusingA, focusingB, cur, carry)
        tail = tail.next
        reversedA = reversedA.next if reversedA else None
        reversedB = reversedB.next if reversedB else None
    
        
    return reverseLinkedList(dummy.next)

def reverseLinkedList(head):
    if (head == None or head.next == None):
        return head
    
    p1 = head
    p2 = head
    while(p2 != None):
        nextNode = p2.next
        p2.next = p1
        p1 = p2
        p2 = nextNode
    head.next = None
    return p1
        

