# Singly-linked lists are already defined with this interface:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def removeKFromList(l, k):
    dummy = ListNode(2599)
    dummy.next = l
    slow = dummy
    fast = l
    
    while(fast != None):
        if fast.value == k:
            slow.next = fast.next
            fast = fast.next
        else:
            fast = fast.next
            slow = slow.next
            
    return dummy.next
            
