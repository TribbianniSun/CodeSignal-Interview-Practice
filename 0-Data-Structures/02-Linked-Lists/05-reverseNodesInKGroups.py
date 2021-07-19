# Singly-linked lists are already defined with this interface:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def reverseNodesInKGroups(head, k):
    dummy = ListNode(-1)
    pre = dummy
    cur = dummy
    dummy.next = head
    num = 0
    while(cur):
        cur = cur.next
        num += 1
    while(num > k):
        cur = pre.next
        for i in range(k - 1):
            t = cur.next
            cur.next = t.next
            t.next = pre.next
            pre.next = t
        pre = cur
        num -= k
    print(num)
    
    return dummy.next
    
