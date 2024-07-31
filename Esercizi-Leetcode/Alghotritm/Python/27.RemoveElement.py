#Elimina tutti gli elementi val dell'array nums e ritorna la lunghezza di nums
class Solution(object):
    def removeElement(self, nums, val):
        i = nums.count(val)
        for x in range(i):
            nums.remove(val)
        return len(nums)