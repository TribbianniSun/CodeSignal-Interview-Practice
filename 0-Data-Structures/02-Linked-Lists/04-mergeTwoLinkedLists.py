# Singly-linked lists are already defined with this interface:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def mergeTwoLinkedLists(l1, l2):
    dummy = ListNode(-2e9)
    tail = dummy
    while l1 or l2:
        if not l1:
            tail.next = l2
            break
        if not l2:
            tail.next = l1
            break
        val1 = l1.value
        val2 = l2.value
        if val1 > val2:
            tail.next = l2
            l2 = l2.next
        else:
            tail.next = l1
            l1 = l1.next
        tail = tail.next
    return dummy.next
