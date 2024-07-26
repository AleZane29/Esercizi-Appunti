#Dati due array merge del primo con il secondo e presenti nel primo n 0 tanti quanti gli elementi del secondo array, infine viene sort
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        for i in range(n):
            nums1[m+i]=nums2[i]
        nums1.sort()