#Dati due array lunghi uguali, restituisce se è possibile renderli uguali effettuando reverse di subarray
class Solution(object):
    def canBeEqual(self, target, arr):
        target.sort()
        arr.sort()
        if target != arr :
            return False
        return True
        