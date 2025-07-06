#Dato un numero intero convertire il suo binario in complementare (invertire 0 con 1 e viceversa) e ritornare l'intero del complementare
class Solution(object):
    def findComplement(self, num):
        i =0
        res = 0
        while num > 0:
            print(2^i)
            if (num % 2) == 0:
                res += pow(2,i)
            num = num / 2
            i+=1
        return res