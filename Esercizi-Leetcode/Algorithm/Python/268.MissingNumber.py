#Dato un array di numeri da 0 a n-1 (con n dimensione array) restituire numero mancante nell'array
class Solution(object):
    def missingNumber(self, nums):
        nums.sort()
        print(nums)
        n =0
        for i in nums:
            if n != i :
                return n
            n+=1
        return len(nums)