import heapq
def kthLargestElement(nums, k):
    pq = []
    for num in nums:
        heapq.heappush(pq, num)
        if len(pq) > k:
            heapq.heappop(pq)
    return heapq.heappop(pq)



# TODO QUICK SELECT ALGORITHM