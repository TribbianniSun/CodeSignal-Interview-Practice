# Singly-linked lists are already defined with this interface:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def isListPalindrome(l):
    
    if(l == None or l.next == None):
        return True
    
    
    # template for finding the midpoint of linkedlist, 
    # newHead will point to the second half (counter + 1) // 2 position
    dummyNode = ListNode(-1)
    dummyNode.next = l
    fast = dummyNode
    slow = dummyNode
    while(fast != None and fast.next != None):
        fast = fast.next.next
        slow = slow.next
    
    newHead = slow.next
    slow.next = None
    
    # reverse the second half
    reversedNewHead = reverseLinkedList(newHead)
    
    # do a regular compare
    while(reversedNewHead != None):
        if reversedNewHead.value != l.value:
            return False
        reversedNewHead = reversedNewHead.next
        l = l.next
    return True
    
def reverseLinkedList(head):
    
    if(head == None or head.next == None):
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
    