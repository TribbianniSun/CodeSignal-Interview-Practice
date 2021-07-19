# Singly-linked lists are already defined with this interface:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def rearrangeLastN(l, n):
    if(l == None or l.next == None):
        return l
    dummy = ListNode(-1)
    dummy.next = l
    slow = dummy
    fast = dummy
    
    # credit to n-holmes for the try except block; amazing defensive coding
    for _ in range(n):
        try:
            fast = fast.next
        except AttributeError:
            break
    
    # if we are at the end, just do nothing and return l
    if(fast.next == None):
        return l
    
    while fast.next != None:
        fast = fast.next
        slow = slow.next
    
    print(slow.value, fast.value)

    fast.next = dummy.next
    dummy.next = slow.next
    slow.next = None
    
    return dummy.next
